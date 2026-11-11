#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1005],b[1005][1005],di[1005][1005],ans=0,vis[1005][1005],bj[1005],flag=0;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]-a[i]<=d){
				b[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			for(int k=i;k<=j;k++){
				flag=0;
				if(b[i][k]==1 && b[k][j]==1){
					if(di[i][j]==di[i][k]+di[k][j]){
						bj[di[i][j]]=1;
					}
					if(di[i][j]>di[i][k]+di[k][j]){
						di[i][j]=di[i][k]+di[k][j];
						bj[di[i][j]]=0;
						cout<<'a';
					}

					
				}
			}
			for(int k=i;k<=n;k++){
				if(bj[di[i][k]]==1){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			di[i][j]=0;
			b[i][j]=0;
			ans=0;
			a[i]=0;
		}
	}
}
	return 0;
}
