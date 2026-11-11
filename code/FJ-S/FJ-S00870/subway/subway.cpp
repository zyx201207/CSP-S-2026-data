#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,b,f,ans=2e5,x,y,bj;
long long w[500005],out[20],in[20],s[4][2000005],t[4][2000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		if(n==1){
			cin>>a;
			for(int k=1;k<=a;k++){
				cin>>s[1][k]>>t[1][k];
			}
		}
		if(n==2){
			cin>>a;
			for(int k=1;k<=a;k++){
				cin>>s[1][k]>>t[1][k];
			}
			cin>>b;
			for(int k=1;k<=b;k++){
				cin>>s[2][k]>>t[2][k];
			}
		}
		if(n==3){
			cin>>a;
			for(int k=1;k<=a;k++){
				cin>>s[1][k]>>t[1][k];
			}
			cin>>b;
			for(int k=1;k<=b;k++){
				cin>>s[2][k]>>t[2][k];
			}
			cin>>f;
			for(int k=1;k<=f;k++){
				cin>>s[3][k]>>t[3][k];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>in[i]>>out[i];
	}
	while(q>1){
		if(n == 1){
			for(int i=1;i<=q;i++){
				x = in[i];
				y = out[i];
				ans = w[x]+t[1][x]+t[1][y]+w[y];
				cout<<ans<<endl;
			}
		}
		if(n == 2){
			for(int i=1;i<=q;i++){
				x = in[i];
				y = out[i];
				for(int k = 1;k <= a;k++){
					if(s[1][k] == in[i]){
						for(int j = 1;j<=a;j++){
							if(s[1][j] == out[i]){
								bj = w[x]+t[1][x]+t[1][y]+w[y];
								ans = min(bj,ans);
							}
						}
					}
				}
				for(int k = 1;k <= b;k++){
					if(s[2][k] == in[i]){
						for(int j = 1;j<=b;j++){
							if(s[2][j] == out[i]){
								bj = w[x]+t[2][x]+t[2][y]+w[y];
								ans = min(bj,ans);
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		q--;
	}
}
