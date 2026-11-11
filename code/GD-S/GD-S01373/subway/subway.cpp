#include<bits/stdc++.h>
using namespace std;
long long c,n,m,dd,q,w[10009],t[10009],d,v[10009][10009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(v,63,sizeof(v));
	cin>>c>>n>>m>>dd>>q;
	if(c>=0&&c<=6){
		for(int i=1;i<=m;i++){
			cin>>t[i];
		}
		for(int i=1;i<=n;i++){
			long long pp;
			cin>>pp;
			for(int j=1;j<=pp;j++){
				dd++;
				long long a1,a2;
				cin>>a1>>a2;
				v[n+m+dd][a1]=a2;
				v[n+m+dd][m+i]=0;
				v[a1][n+m+dd]=a2;
				v[m+i][n+m+dd]=0;
			}
		}
		for(int k=1;k<=(n+m+dd);k++){
			for(int i=1;i<=(m+n+dd);i++){
				for(int j=1;j<=(n+m+dd);j++){
					if(v[i][j]>v[i][k]+v[j][k]){
						v[i][j]=v[i][k]+v[j][k];
					}
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long a1,a2;
			cin>>a1>>a2;
			cout<<t[a1]+t[a2]+v[a1][a2]<<endl;
		}
	}
	else if(c>=7&&c<=11){
		for(int i=1;i<=m;i++){
			cin>>t[i];
		}
		for(int i=1;i<=n;i++){
			long long pp;
			cin>>pp;
			long long a1,a2;
			if(pp==1){
				cin>>a1>>a2;
			}
			if(pp==2){
				long long a1,a2,a3,a4;
				cin>>a1>>a2>>a3>>a4;
				dd++;
				v[m+dd][a1]=a2;
				v[a1][m+dd]=a2;
				dd++;
				v[a3][m+dd]=a4;
				v[m+dd][a3]=a4;
				v[m+dd-1][m+dd]=0;
				v[m+dd][m+dd-1]=0;
			}
			
		}
		
		for(int k=1;k<=(m+dd);k++){
			for(int i=1;i<=(m+dd);i++){
				for(int j=1;j<=(m+dd);j++){
					if(v[i][j]>v[i][k]+v[j][k]){
						v[i][j]=v[i][k]+v[j][k];
					}
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long a1,a2;
			cin>>a1>>a2;
			cout<<t[a1]+t[a2]+v[a1][a2]<<endl;
		}
	}
	
} 
