#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int C,T,n,d,x[N],l[N],r[N]; 
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++){
			int L=0,R=i,res=i;
			while(L+1<R){
				int mid=(L+R)>>1;
				if(x[i]-d<=x[mid])
					res=mid,R=mid;
				else
					L=mid;
			}
			l[i]=i-res;
			if(i==1)l[i]=0;
			L=i,R=n+1,res=i;
			while(L+1<R){
				int mid=(L+R)>>1;
				if(x[i]+d>=x[mid])
					res=mid,L=mid;
				else
					R=mid;
			}
			r[i]=max(0ll,res-i);
			if(i==n)r[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(r[i]+l[j]==j-i+1)
					ans++;
		cout<<ans<<"\n";
	}	
	return 0;
}
