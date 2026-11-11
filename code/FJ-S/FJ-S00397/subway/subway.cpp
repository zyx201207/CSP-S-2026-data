#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 5e2 + 5 ;
const int M = 5e5 + 5 ;
int c,n,m,d,p;
int b[M];
int a[22][N];
int o[M][22];
int r[22][22];
int q;
int ans=INT_MAX;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		cin>>q;
		for(int j=1;j<=q;j++){
			int a1,a2;
			cin>>a1>>a2;
			a[i][j]=a1;
			o[a1][i]=a2;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(o[i][j]!=0){
				for(int k=j+1;k<=n;k++){
					if(o[i][k]!=0){
						if(r[j][k]==0)r[j][k]=INT_MAX;
						r[j][k]=min(r[j][k],o[i][j]+o[i][k]);
						r[k][j]=r[j][k];
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(r[i][j]==0)r[i][j]=INT_MAX;
				if(i==j)r[i][j]=0;
				if((r[k][i]!=0&&r[k][j]!=0)||(r[k][i]!=INT_MAX&&r[k][j]!=INT_MAX)){
					r[i][j]=min(r[i][j],r[k][j]+r[k][i]);
					r[j][i]=r[i][j];
				}
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<o[i][j]<<" ";
		}cout<<endl;
	}*/
	/*for(int i=1;i<=n;i++){
	 for(int j=1;j<=n;j++)
	 cout<<r[i][j]<<" ";
	cout<<endl;
	}//*/
	for(int i=1;i<=p;i++){
		int a1,a2;
		cin>>a1>>a2;
		for(int j=1;j<=n;j++){
			if(o[a1][j]!=0){
				for(int k=1;k<=n;k++){
					if(o[a2][k]!=0){
						ans=min(ans,r[j][k]+o[a1][j]+o[a2][k]);
					}
				}
			}
		}
		cout<<b[a1]+b[a2]+ans<<endl;
	}
	return 0;
}

