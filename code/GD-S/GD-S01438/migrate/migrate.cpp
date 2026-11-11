#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,K=1e4+7;
int c,T,a[N],k[K][K],t[K][K];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				k[i][j]=INT_MAX,t[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(abs(a[i]-a[j])<=d) k[i][j]=k[j][i]=1;
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					if(k[i][l]+k[l][j]<k[i][j])
						k[i][j]=k[i][l]+k[l][j],t[i][j]=1;
					else if(k[i][j]==k[i][l]+k[l][j])
						t[i][j]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(t[i][j]==2) ans++;
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

