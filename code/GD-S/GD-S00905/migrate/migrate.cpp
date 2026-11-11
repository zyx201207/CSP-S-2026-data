#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll c,t,Inf=1e18;
ll n,d,r,R,ans,a[2000010],dis[2000010],f[2000010];
ll topc,w,l[2000010];
vector<int> g[8010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		rep(i,1,n) cin >> a[i];
		sort(a+1,a+n+1);
		rep(i,1,n){
			r=i-1;R=i;
			dis[i]=0;topc=0;w=1;
			rep(j,i+1,n) dis[j]=Inf,f[j]=0;
			f[i]=1;
			rep(j,i,n){
				while(r<n && a[r+1]-a[j]<=d) r++;
				rep(k,j+1,r){
					if(dis[k]>=dis[j]+1) dis[k]=dis[j]+1,f[k]+=f[j];
				}
			}
			rep(j,i+1,n){
				if(f[j]==2) ans++;
			}
		}
		cout << ans << "\n";
		ans=0;
	}
	return 0;
}
/*
4 3
1
2
3
5
666666666666666663
111111111111111105 
333333333333333326 
555555555555555547 
999999999999999989
*/
