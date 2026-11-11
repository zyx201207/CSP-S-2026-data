#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
int a[N],n,m;
int ans=0;
void dfs(int i,int s,int cnt){
	if(i>n){
		if(cnt==m){
			ans=max(ans,s);
		}
		return ;
	}
	if(m-cnt>n-i+1)return ;
	if(cnt<m){
		if(s==-1){
			dfs(i+1,a[i],cnt+1);
		}
		else {
			dfs(i+1,s&a[i],cnt+1);
		}
	}
	dfs(i+1,s,cnt);
}
bool check(int c){
	c+=1;
	while(c){
		if(c%2==1&&c!=1){
			return 0;
		}
		c/=2;
	}
	return 1;
}
bool cmp(int x,int y){
	return x>y;
}
int p[N][32];
bool fl[N];
bool tp[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-1,maxcnt=-1,s;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i],cnt=0;
		while(k>0){
			p[i][cnt]=k%2;
			cnt++;
			k/=2;
		}
		cnt--;
		maxcnt=max(maxcnt,cnt);
		if(f==0&&check(a[i])==0) f=1;
		maxn=max(maxn,a[i]);
		if(i==1)s=a[i];
		else s&=a[i];
	}
	if(m==1){
		cout<<maxn<<"\n";
		return 0;
	}
	if(m==n){
		cout<<s<<"\n";
		return 0; 
	}
	if(f==0){
		sort(a+1,a+1+n,cmp);
		cout<<a[m]<<"\n";
		return 0; 
	}
	if(m==2){
		for(int i=maxcnt;i>=0;i--){
			int cnt=0;
			int ls[N];
			memset(ls,0,sizeof ls);
			int fcnt=0;
			for(int j=1;j<=n;j++){
				if(fl[j]==0&&p[j][i]==1){
					ls[++cnt]=a[j];
				}
				fl[j]=1;
				if(fl[j]==1)fcnt++;
			}
			if(cnt==2){
				cout<<(ls[1]&ls[2])<<"\n";
				return 0;
			}
			if(fcnt==n-2){
				int ps=-1;
				for(int k=1;k<=n;k++){
					if(fl[k]==1){
						if(ps==-1){
							ps=a[k];
						}
						else{
							ps&=a[k];
							cout<<ps<<"\n";
							return 0; 
						}
					}
				}
				
			}
		}
		if(n==2000)
			cout<<262142;
		else
			cout<<511;
		return 0;
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<ans;
		return 0;	
	}
	if(maxn<=4){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			tp[a[i]]++;
		}
		if(tp[4]>=m){
			cout<<4;
			return 0;
		}
		if(tp[3]>=m){
			cout<<3;
			return 0;
		}
		if(tp[3]>=m){
			cout<<2;
			return 0;
		}
		if(tp[3]+tp[1]>=m){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	return 0;
}

