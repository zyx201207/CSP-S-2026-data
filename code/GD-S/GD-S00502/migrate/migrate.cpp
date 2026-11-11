#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
const ll inf=1e18;
int c,T,n;
ll D,x[N];
int l[N],r[N],dis[N],rx[N];
ll f[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			l[i]=lower_bound(x+1,x+1+i,x[i]-D)-x;
			r[i]=upper_bound(x+i,x+1+n,x[i]+D)-x-1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			f[i]=1,dis[i]=0,rx[0]=i;
			for(int j=i;j<=n;j++){
				if(j>i){
					if(j>rx[dis[j-1]]) dis[j]=dis[j-1]+1;
					else dis[j]=dis[j-1];
				}
				s[j]+=s[j-1];
				if(j>i) f[j]=s[j];
//				cout<<"add "<<rx[dis[j]]+1<<" "<<r[j]<<":"<<f[j]<<endl;
				s[rx[dis[j]]+1]+=f[j];
				s[r[j]+1]-=f[j];
				rx[dis[j]+1]=max(rx[dis[j]+1],r[j]);
			}
//			for(int j=i+1;j<=n;j++) cout<<f[j]<<" ";
//			cout<<":";
//			for(int j=0;j<=4;j++) cout<<rx[j]<<" ";
//			cout<<endl;
			for(int j=i+1;j<=n;j++)
			  if(f[j]==2) ans++;
			for(int j=0;j<=n+1;j++) f[j]=0,dis[j]=n+1,s[j]=0,rx[j]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 3
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
