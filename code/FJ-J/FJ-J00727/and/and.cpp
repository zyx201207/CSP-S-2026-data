#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int N=2e5+5;
ll n,m,a[N],s[N][35],tot[35],vis[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		ll x=a[i],k=31;
		while(x){
			s[i][k]=x%2;
			tot[k]+=x%2;
			k--;
			x/=2;
		}
	}
	FOR(i,0,31){
		if(tot[i]>=m){
			ans+=pow(2,31-i);
			FOR(j,1,n){
				if(!vis[j]){
					if(!s[j][i]){
						vis[j]=1;
						FOR(k,i,31){
							tot[k]-=s[j][k];
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
