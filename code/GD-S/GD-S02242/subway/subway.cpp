#include<bits/stdc++.h>
using namespace std;
queue<int>qq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int zh[m+1]={};
	bool vis[m+1]={};
	for(int i=1;i<=m;i++){
		cin>>zh[i];
	}
	if(c>=12 && c<=19){
		bool foot[m+1][m+1]={};
		int T=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int ss[k+1]={};
			for(int j=1;j<=k;j++){
				int a,t;
				cin>>a>>t;
				T=t;
				if(j==1){
					ss[j]=a;
				}else{
					for(int l=1;l<j;l++){
						foot[l][j]=1;
						foot[j][l]=1;
					}
				}
			}
		}
	}
	return 0;
}
