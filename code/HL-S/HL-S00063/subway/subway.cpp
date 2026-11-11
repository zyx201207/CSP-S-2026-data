#include<bits/stdc++.h>
using namespace std;
int w[500010],m[510][510],a[510][50010],t[510][50010],k[510],n;

int f(int x,int y){
	if(m[x][y]){
		return m[x][y];
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(m[x][j]&&m[j][y]){
					return m[x][y]+m[x][j]+m[j][y];
				}
			}
		}
	}
}
int main(){
	int c,M,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>M>>d>>q;
	for(int i=1;i<=M;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>k[j];
		for(int i=1;i<=k[j];i++){
			cin>>a[j][i]>>t[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int p=j;p<=k[i];p++){
				m[a[i][j]][a[i][p]]=m[a[i][p]][a[i][j]]=t[i][j]+t[i][p];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			for(int l=1;l<=k[i];l++){
//				for(int r=1;r<=k[j];r++){
//					m[a[i][l]][a[j][r]]=m[a[j][r]][a[i][l]]=t[i][l]+t[j][r];
//				}
//			}
//		}
//	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		f(x,y);
		cout<<w[x]+w[y]+f(x,y)<<endl;
	}
	return 0;
}
