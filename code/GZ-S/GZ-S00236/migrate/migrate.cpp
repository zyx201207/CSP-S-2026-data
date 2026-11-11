//贵阳市第三实验中学 赵行健 GZ-S00236 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define int long long
int len[N][30];
int a[N];
int n,d;
void find(int u){
	for(int i = u;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				for(int k = 0;k<25;k++){
					if(len[i][k]>0&&len[j][k+1]>0){
						len[j][k+1]++;
					}
					else if(len[i][k]>0){
						len[j][k+1]=1;
					}
				}
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			for(int k = 0;k<=25;k++){
				len[j][k]=0;
			}
		}
		len[i][0]=1;
		find(i);
		for(int j = i;j<=n;j++){
			for(int k = 1;k<=25;k++){
				if(len[j][k]>0){
					if(len[j][k]==2) ans++;
					break;
				}

			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		solve();
	}
	
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
