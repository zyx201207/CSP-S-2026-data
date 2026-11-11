#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,i1,x,y,cnt,f=1;
int w[5005],a[5005][5005],t[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>i1;
		for(int j=1;j<=2*i1;j+=2){
			cin>>a[i][f];
			cin>>t[i][f];
			f++;
		}	
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>x>>y;
		cnt+=t[x][x]+w[x];
		for(int j=x-1;j<=y+1;j++){
			cnt+=a[j][j]+t[j+1][j+1];
		}
		cnt+=t[y][y]+w[y]+1;
		cout<<cnt<<"\n";
	}
	return 0;
}
