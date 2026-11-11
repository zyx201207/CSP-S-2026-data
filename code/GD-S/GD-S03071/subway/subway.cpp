#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500001][500001],num,x,x_num1,y_num1,x_num,y_num,y,w[500001],t[500001][500001];
void note(){
	if(x_num==y_num){
		for(int i=x_num1;i<=y_num1;i++){
			num+=t[x_num][i]*2;
		}
	}
	cout<<num;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k;o++){
				if(a[j][o]==x){
					x_num=j;
					x_num1=o;
				}
				else if(a[j][o]==y){
					y_num=j;
					y_num1=o;
					break;
				}
			}
		}
		note();
	}
	return 0;
}
