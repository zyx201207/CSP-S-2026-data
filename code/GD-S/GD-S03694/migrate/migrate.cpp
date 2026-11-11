#include<bits/stdc++.h>
# define Maxn 2000005
# define ll long long
# define fir first
# define sec second
using namespace std;
namespace Read{
	ll fg;
	char ch;
	void readint(int &x) {
		fg=1,x=0;
		ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') fg=-1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
		x*=fg;
	}
	void readll(ll &x) {
		fg=1,x=0;
		ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') fg=-1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
		x*=fg;
	}
};
using namespace Read;

int cid,T,n;
ll D,a[Maxn];

struct Baoli{
	int f[Maxn],g[Maxn];
	int cnt[Maxn];
	int ans;
		
	void Solve() {
		while(T--) {
			readint(n),readll(D);
			for(int i=1;i<=n;i++) readll(a[i]);
			
			for(int i=1;i<=n;i++) {
				f[i]=0,g[i]=1,cnt[0]=1;
				int lst=i;
				for(int j=i+1;j<=n;j++) {
					while(a[j]-a[lst]>D) {
						cnt[f[lst]]-=g[lst];
						lst++;
					}
					if(lst==j) break;
					
					f[j]=f[lst]+1;
					g[j]=cnt[f[lst]];
					if(g[j]>2) g[j]=3;
					ans+=(g[j]==2);
					
					cnt[f[j]]+=g[j];
				}
				
//				for(int j=1;j<=n;j++) printf("%d ",f[j]);
//				printf("\n");
//				for(int j=1;j<=n;j++) printf("%d ",g[j]);
//				printf("\n");
				
				for(int j=1;j<=n;j++) cnt[f[j]]=0;
			}
			printf("%d\n",ans),ans=0;
		}
	}
}Baoli;

struct SolveA{
	int f[Maxn],g[Maxn];
	int cnt[Maxn];
	ll ans;
	void Solve() {
		while(T--) {
			readint(n),readll(D);
			for(int i=1;i<=n;i++) readll(a[i]);
			
			if(n==1) {printf("0\n");continue;}
			if(a[2]-a[1]>D) {printf("0\n");continue;}
			
			f[1]=0,g[1]=1,cnt[0]=1;
			int lst=1;
			vector<int> vec;
			for(int j=2;j<=n;j++) {
				while(a[j]-a[lst]>D) {
					cnt[f[lst]]-=g[lst];
					lst++;
				}
				if(lst==j) break;
				
				f[j]=f[lst]+1;
				g[j]=cnt[f[lst]];
				if(g[j]>2) g[j]=3;
				if(g[j]==2) vec.push_back(j);
				
				cnt[f[j]]+=g[j];
			}
			for(int j=1;j<=n;j++) cnt[f[j]]=0;
			
			for(int i=1;i<=n;i++) {
				int l=0,r=vec.size()-1,mid,p=-1;
				while(l<=r) {
					mid=(l+r)>>1;
					if(vec[mid]+i-1<=n) p=mid,l=mid+1;
					else r=mid-1;
				}
				ans+=p+1;
			}
			printf("%lld\n",ans),ans=0;
		}
	}
}SolveA;

struct SolveC{
	ll ans;
	
	int st[Maxn],g[Maxn],sum;
	vector<pair<int,int>> vec; 
	
	void Solve() {
		while(T--) {
			readint(n),readll(D);
			for(int i=1;i<=n;i++) readll(a[i]);
			
			int lst=n;
			st[n]=0;
			for(int i=n-1;i>=1;i--) {
				while(a[lst]-a[i]>D) lst--;
				if(i!=lst) st[i]=lst;
				else st[i]=0;
			}
			
			for(int i=1;i<=n;i++) {
				vec.clear();
				vec.push_back({i,i});
				while(1) {
					int p=vec.back().sec;
					if(!st[p]) break;
					vec.push_back({p+1,st[p]});
				}
				
//				for(pair<int,int> it:vec) printf("%d %d\n",it.fir,it.sec);
//				printf("\n");
				
				g[i]=1;
				for(int j=1;j<(int)vec.size();j++) {
					for(int k=max(vec[j].fir,vec[j].sec-2);k<=vec[j].sec;k++) {
						g[k]=0;
//						for(int h=max(vec[j-1].fir,vec[j-1].sec-2);h<=vec[j-1].sec;h++) {
//							if(a[k]-a[h]<=D) g[k]+=g[h];
//						}
						if(vec[j-1].fir<=vec[j-1].sec&&a[k]-a[vec[j-1].sec]<=D) g[k]+=g[vec[j-1].sec]; 
						if(vec[j-1].fir<=vec[j-1].sec-1&&a[k]-a[vec[j-1].sec-1]<=D) g[k]+=g[vec[j-1].sec-1]; 
						if(vec[j-1].fir<=vec[j-1].sec-2&&a[k]-a[vec[j-1].sec-2]<=D) g[k]+=g[vec[j-1].sec-2]; 
						if(g[k]>2) g[k]=3;
//						printf("G %d: %d\n",k,g[k]);
					}
					
					int l=vec[j].fir,r=vec[j].sec,mid,p1=-1,p2=-1;
					while(l<=r) {
						mid=(l+r)>>1;
						sum=0;
						if(vec[j-1].fir<=vec[j-1].sec&&a[mid]-a[vec[j-1].sec]<=D) sum+=g[vec[j-1].sec]; 
						if(vec[j-1].fir<=vec[j-1].sec-1&&a[mid]-a[vec[j-1].sec-1]<=D) sum+=g[vec[j-1].sec-1]; 
						if(vec[j-1].fir<=vec[j-1].sec-2&&a[mid]-a[vec[j-1].sec-2]<=D) sum+=g[vec[j-1].sec-2]; 
//						for(int h=max(vec[j-1].fir,vec[j-1].sec-2);h<=vec[j-1].sec;h++) {
//							if(a[mid]-a[h]<=D) sum+=g[h];
//						}
						if(sum>=2) p1=mid,l=mid+1;
						else r=mid-1;
					}
					
					if(p1==-1) continue; 
					l=vec[j].fir,r=p1;
					while(l<=r) {
						mid=(l+r)>>1;	
						sum=0;
						if(vec[j-1].fir<=vec[j-1].sec&&a[mid]-a[vec[j-1].sec]<=D) sum+=g[vec[j-1].sec]; 
						if(vec[j-1].fir<=vec[j-1].sec-1&&a[mid]-a[vec[j-1].sec-1]<=D) sum+=g[vec[j-1].sec-1]; 
						if(vec[j-1].fir<=vec[j-1].sec-2&&a[mid]-a[vec[j-1].sec-2]<=D) sum+=g[vec[j-1].sec-2];
//						for(int h=max(vec[j-1].fir,vec[j-1].sec-2);h<=vec[j-1].sec;h++) {
//							if(a[mid]-a[h]<=D) sum+=g[h];
//						}
						if(sum<=2) p2=mid,r=mid-1;
						else l=mid+1;
					}
					
					if(p1!=-1&&p2!=-1) ans+=p1-p2+1;
				}
			}
			printf("%lld\n",ans);
			ans=0;
		}	
	}
}SolveC;

int main() {
//	freopen("migrate5.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	double st=clock();
	readint(cid),readint(T);
	if(cid<=10) {
		Baoli.Solve();
		return 0;
	}
	if(cid==11||cid==12) {
		SolveA.Solve();
		return 0;
	}
	if(cid>=13&&cid<=18) {
		SolveC.Solve();
//		printf("%.3lf\n",(double)(clock()-st)/CLOCKS_PER_SEC);
		return 0;
	}
	Baoli.Solve();
	return 0;
}
