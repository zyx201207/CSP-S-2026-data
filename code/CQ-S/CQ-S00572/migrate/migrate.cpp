#include<bits/stdc++.h>
using namespace std;
namespace bf{
	const int mn=2000003;
	long long a[mn];
	vector<int>sons[mn];
	int d[mn],f[mn];
	int main(int n,long long dis){
		long long cnt=0;
		for(int i=1;i<=n;i++)
			sons[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=dis){
					sons[i].push_back(j);
					sons[j].push_back(i);
				}
		for(int s=1;s<=n;s++){
			for(int i=1;i<=n;i++){
				d[i]=214748364;
				f[i]=0;
			}
			queue<int>q;
			d[s]=0;
			f[s]=1;
			q.push(s);
			while(q.size()){
				int x=q.front();
				q.pop();
//					cerr<<s<<" "<<x<<endl;
				for(int i=0;i<sons[x].size();i++){
					if(d[sons[x][i]]>d[x]+1){
						d[sons[x][i]]=d[x]+1;
						f[sons[x][i]]=0;
						q.push(sons[x][i]);
					}
					if(d[sons[x][i]]==d[x]+1)
						f[sons[x][i]]=min(f[sons[x][i]]+f[x],3);
				}
			}
			for(int i=s+1;i<=n;i++){
//					cerr<<s<<" -- "<<i<<" "<<d[i]<<" "<<f[i]<<endl;
				if(f[i]==2){
//						cerr<<s<<" -- "<<i<<endl;
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
		return 0;
	}
}
namespace estidi{
	const int mn=2000003;
	long long a[mn];
	int isc[mn],lm[mn],rm[mn],tlcnt[mn],trcnt[mn],lg1[mn],rg1[mn],lg2[mn],rg2[mn];
	int main(){
		int sc,tc,n,np,l,r,now1,now2;
		long long d,cnt;
		scanf("%d%d",&sc,&tc);
		while(tc--){
			scanf("%d%lld",&n,&d);
			if(n<=5000){
				bf::main(n,d);
				continue;
			}
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				isc[i]=0;
				tlcnt[i]=0;
				trcnt[i]=0;
				lg1[i]=0;
				rg1[i]=0;
				lg2[i]=0;
				rg2[i]=0;
			}
			for(int i=1;i<=n;i++)
				if(i==1||i==n||a[i+1]-a[i-1]>d)
					isc[i]=1;
			cnt=0;
			np=1;
			for(int i=1;i<=n;i++){
				while(np+1<=n&&a[np+1]-a[i]<=d)
					np++;
				rm[i]=np;
				assert(rm[i]>=i);
			}
			np=n;
			for(int i=n;i>=1;i--){
				while(np-1>=1&&a[i]-a[np-1]<=d)
					np--;
				lm[i]=np;
				assert(lm[i]<=i);
			}
			l=1;
			r=1;
			while(r!=n){
				assert(l!=r||isc[l]);
				if(l==r){
					for(int i=r+1;i<=rm[r];i++)
						tlcnt[i]=1;
				}
				else{
					if(r-l+1==2){
						int fl=2;
						if(tlcnt[l]+tlcnt[r]>=3)
							fl=3;
						for(int i=r+1;i<=rm[l];i++)
							tlcnt[i]=fl;
						for(int i=rm[l]+1;i<=rm[r];i++)
							tlcnt[i]=tlcnt[r];
					}
					else{
						for(int i=r+1;i<=rm[r-2];i++)
							tlcnt[i]=3;
						int fl=2;
						if(tlcnt[r-1]+tlcnt[r]>=3)
							fl=3;
						for(int i=rm[r-2]+1;i<=rm[r-1];i++)
							tlcnt[i]=fl;
						for(int i=rm[r-1]+1;i<=rm[r];i++)
							tlcnt[i]=tlcnt[r];
					}
				}
				l=r+1;
				r=rm[r];
				while(l!=n&&rm[l]<=r)
					l++;
				if(l>r){
					assert(l==r+1);
					r=l;
				}
			}
			l=n;
			r=n;
			while(l!=1){
				assert(l!=r||isc[l]);
				if(l==r){
					for(int i=l-1;i>=lm[l];i--)
						trcnt[i]=1;
				}
				else{
					if(r-l+1==2){
						int fl=2;
						if(trcnt[l]+trcnt[r]>=3)
							fl=3;
						for(int i=l-1;i>=lm[r];i--)
							trcnt[i]=fl;
						for(int i=lm[r]-1;i>=lm[l];i--)
							trcnt[i]=trcnt[l];
					}
					else{
						for(int i=l-1;i>=lm[l+2];i--)
							trcnt[i]=3;
						int fl=2;
						if(trcnt[l+1]+trcnt[l]>=3)
							fl=3;
						for(int i=lm[l+2]-1;i>=lm[l+1];i--)
							trcnt[i]=fl;
						for(int i=lm[l+1]-1;i>=lm[l];i--)
							trcnt[i]=trcnt[l];
					}
				}
				r=l-1;
				l=lm[l];
				while(r!=1&&lm[r]>=l)
					r--;
				if(l>r){
					assert(l==r+1);
					l=r;
				}
			}
			now1=0;
			now2=0;
			for(int i=1;i<=n;i++){
				assert(0<=tlcnt[i]&&tlcnt[i]<=3&&0<=trcnt[i]&&trcnt[i]<=3);
				if(isc[i]){
					now1++;
					rg1[i]=now1;
					rg2[i]=now2;
					if(trcnt[i]==0||trcnt[i]==3){
						now1=0;
						now2=0;
					}
					if(trcnt[i]==2){
						now2=now1;
						now1=0;
					}
				}
				else{
					if(trcnt[i]==1)
						now1++;
					if(trcnt[i]==2)
						now2++;
				}
			}
			now1=0;
			now2=0;
			for(int i=n;i>=1;i--){
				if(isc[i]){
					lg1[i]=now1+1;
					lg2[i]=now2;
					now1=0;
					now2=0;
				}
				else{
					if(tlcnt[i]==1)
						now1++;
					if(tlcnt[i]==2)
						now2++;
				}
			}
			for(int i=1;i<=n;i++){
//				cerr<<i<<" "<<a[i]<<" "<<tlcnt[i]<<" "<<trcnt[i]<<" "<<isc[i]<<" "<<lg1[i]<<" "<<rg2[i]<<" "<<lg2[i]<<" "<<rg1[i]<<endl;
				cnt+=(long long)lg1[i]*rg2[i]+(long long)lg2[i]*rg1[i];
			}
//			cerr<<cnt;
//			for(int i=1;i+3<=n;i++){//only dis==2?
//				if(isc[i]==0&&isc[i+3]==0&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d){
//					now1=i;
//					while(now1-1>=1&&isc[now1-1]==0&&a[i+2]-a[now1-1]<=d)
//						now1--;
//					now2=i+3;
//					while(now2+1<=n&&isc[now2+1]==0&&a[now2+1]-a[i+1]<=d)
//						now2++;
//					cnt+=(long long)(i-now1+1)*(now2-(i+3)+1);
//				}
//			}
			for(int i=1;i+1<=n;i++){//only dis==2? no.
				if(a[i+1]-a[i]<=d){
					l=lm[i+1];
					r=rm[i];
					if(isc[l])
						l++;
					if(isc[r])
						r--;
					if(l>=i||r<=i+1)
						continue;
					int rr=rm[i-1],ll=lm[i+2];
					if(isc[ll])
						ll++;
					if(isc[rr])
						rr--;
//					cerr<<l<<" "<<ll<<" ["<<i<<" "<<i+1<<"] "<<rr<<" "<<r<<endl;
					cnt+=(long long)(ll-l)*(r-rr);
				}
			}
			printf("%lld\n",cnt);
		}
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	estidi::main();
	return 0;
}
