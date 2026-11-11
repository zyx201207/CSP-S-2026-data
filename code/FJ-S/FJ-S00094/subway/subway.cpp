#include<bits/stdc++.h>
using namespace std; 
int c,n,m,d,g,w[500005],t[505][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>g;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t[i][j];
		}
	}
	for(int z=1;z<=g;z++){
		int x,y,cnt=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(t[i][j]==y){
					cnt+=t[i][j];
				}
				if(t[i][j]==x){
					cnt+=t[i][j];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
