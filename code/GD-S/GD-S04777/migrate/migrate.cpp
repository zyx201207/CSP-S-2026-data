#include<bits/stdc++.h>
#define int __int128
using namespace std;
long long T;
int x[2000005];
long long f[2000005],f2[2000005];
bool bz[2000005];
long long nxt[2000005],lst[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long c;
	cin>>c;
	cin>>T;
	while(T--){
		long long n;
		int d;
		long long z;
		cin>>n>>z;
		d=z;
		int l=1;
		for(int i=1;i<=n;++i){
			long long p=0;
			cin>>p;
			x[i]=p;
			f[i]=0,f2[i]=0;
		}
		l=n;
		x[0]=-1e18;
		for(int i=n-1;i>=1;--i){
			while(x[l]-x[i]>d)--l;
			nxt[i]=l;
		}
		f2[n]=0;
		for(int i=n-1;i>=2;--i){
			if(x[nxt[i]]-x[i-1]>d){
				f2[i]+=f2[nxt[i]]+1;
			}
		}
		f[1]=0;
		for(int i=1;i<n;++i){
			if(x[nxt[i]]-x[i-1]>d&&i!=1){
				f[nxt[i]]+=f[i];
			}
			f[nxt[i]]++;
			f[i]++;
		}
		l=n+1;
		long long ans=0;
		for(int i=3;i<n;++i){
			if(nxt[i]==i)continue;
			if(x[nxt[i]]-x[i-1]<=d&&x[nxt[i]]-x[i-2]>d){
				ans+=(f2[nxt[i]])*(f[i]-1);
			}
			int l=i+1,r=nxt[i],an1=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(x[mid]-x[i-2]<=d){
					an1=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			if(an1==0)an1=i+1;
			else an1++;
			l=i+1,r=nxt[i];
			long long an2=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(x[mid]-x[i-1]>d){
					an2=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(an2==0)an2=nxt[i];
			else an2--;
			if(an1&&an2&&an1<=an2){
				ans+=(f[i]-1)*(an2-an1+1); 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
