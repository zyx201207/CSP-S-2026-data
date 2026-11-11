#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;
long long a[maxn],f[maxn][maxn],ans[maxn][maxn],h,c,cs,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>cs;
	while(cs--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		} 
		fill(ans[0],ans[maxn],0);
		fill(f[0],f[maxn],2e18);
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					f[i][j] = (i!=j);
				}
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = i;j<=n;j++){
					long long t = f[i][k]+f[k][j];
					if(f[i][j]>t){
						f[i][j] = t;
						ans[i][j] = 1;
					}
					else if(f[i][j]==t){
						ans[i][j]++;
					} 
				}
			}
		}
		h = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if(ans[i][j]==2){
					h++;
				}
			}
		}
		cout<<h<<"\n";
	}
	return 0;
}
