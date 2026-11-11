#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x,y,h;
int w[5005];
int a[5005][5005];
int ans[5005][5005];
int rans[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int cop=t;
	while(t--){
		cin>>n>>d;
		if(c==11 || c==12){
		cin>>x>>y;
		for(int i=1;i<=n-2;i++){
			cin>>h;
		}
		int d=y-x;
		int ca=d/x;
		int g=0; 
		rans[t]=max(g,n-ca*2+1); 
	    }else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
		        a[i][j]=1000000000;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(w[j]-w[i]<=d){
					a[i][j]=1;
					ans[i][j]=1;
				}
			} 
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i][j]==a[i][k]+a[k][j]){
						ans[i][j]+=(ans[i][k]*ans[k][j]);
					}
					if(a[i][j]>a[i][k]+a[k][j]){
						ans[i][j]=ans[i][k]*ans[k][j];
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans[i][j]==2){
					cnt++;
				}
			}
		}
		rans[t]=cnt;
	}
}
	for(int i=cop-1;i>=0;i--){
		cout<<rans[i]<<endl;
	}
	return 0;
}
