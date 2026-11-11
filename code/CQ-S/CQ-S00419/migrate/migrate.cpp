#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
const int N=2000005;
int c;
ll n,d,x[N];
const int N10=5005;
int L[13][N10],R[13][N10],rs[13][N10],ls[13][N10];
il void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(c<=10){
		for(int i=1,j=0;i<=n;i++){
			while(j+1<=n&&x[j+1]<=x[i]+d)j++;
			R[0][i]=j;
			rs[0][i]=j;
		}
		for(int i=n,j=n+1;i>=0;i--){
			while(j-1>=1&&x[j-1]>=x[i]-d)j--;
			L[0][i]=j;
			ls[0][i]=j-1;
		}
		for(int i=1;i<=__lg(n);i++){
			for(int j=1;j<=n;j++){
				R[i][j]=R[i-1][R[i-1][j]];
				L[i][j]=L[i-1][L[i-1][j]];
				rs[i][j]=rs[i-1][j]+rs[i-1][R[i-1][j]];
				ls[i][j]=ls[i-1][j]+ls[i-1][L[i-1][j]];
			}
		}
		ll cnt=0;
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				ll dis=0,sum=0; int u=x,v=y;
				for(int i=__lg(n);i>=0;i--){
					if(R[i][u]<y){
						dis+=(1<<i);
						sum+=rs[i][u]-ls[i][v];
						u=R[i][u],v=L[i][v];
					}
				}
				dis++;
				if(dis==sum)cnt++;
			}
		}
		cout<<cnt<<'\n';
		return;
	}
	if(c<=12){
		ll k=x[2]-x[1];
		ll st=d/k; int cnt=0;
		if(st<=1)return cout<<"0\n",void();
		for(int i=1;i<=n;i++){
			if(i+st*2-1<=n)cnt++;
		}
		cout<<cnt<<'\n';
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t; cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
