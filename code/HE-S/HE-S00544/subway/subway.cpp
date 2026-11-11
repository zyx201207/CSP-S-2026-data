#include<bits/stdc++.h>
using namespace std;
int w[10009],xianlu[10009][10009];
int t[10009][10009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,z,xa,ya,num=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>z;
		for(int j=0;j<z;j++){
			cin>>xianlu[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(xianlu[j][k]==x){
					xa=j;
				}
			}
		}
		num=0;
		for(x;x<m;x++){
			num += t[xa][x-1] + w[x-1];
			if(x==y){
				cout<<num<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
