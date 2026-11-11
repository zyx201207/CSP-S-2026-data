#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[500005];
int a[5005][5005];
int times[5005][5005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while (T--){
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=5001;i++){
			for (int j=1;j<=5001;j++){
				a[i][j]=1e9;
			}
		}
		memset(times,0,sizeof(times));
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				if (x[j]-x[i]<=d){
					a[i][j]=1;
				}
				else{
					break;
				}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				for (int k=i;k<=j;k++){
					if (a[i][k]+a[k][j]<a[i][j]){
						a[i][j]=a[i][k]+a[k][j];
						times[i][j]=1;
					}
					else if (a[i][k]+a[k][j]==a[i][j]){
						times[i][j]++;
					}
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans+=(times[i][j]==2 ? 1:0);
			}
		}
		cout<<ans<<endl;
	}
}
