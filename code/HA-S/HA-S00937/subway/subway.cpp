#include <bits/stdc++.h>
using namespace std;
int a[10010],b[1001][1001]={0};
int a1[10010],a2[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		for(int j=1;j<=u;j++){
			cin>>a1[j]>>a2[j];
			b[i][a1[j]]=a2[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum=0;
		cin>>x>>y;
		int min=INT_MAX,xian=0;
		for(int j=1;j<=n;j++){
			if(b[j][x]<min&&b[j][x]!=0){
				xian=j;
			}
		}
		sum+=a[x]+a[y];
		for(int j=x;j<=y;j++){
			sum+=b[xian][j];
			if(b[xian][j+1]==0){
			for(int k=1;k<=n;k++){
				if(xian+1<=n){
					xian+=1;
					if(b[xian][j+1]!=0){
						break;
					}
				}else{
						xian=1;	
					}
					sum+=b[xian][j];
			}
			}	
		}
		cout<<sum<<"\n";
	}
	return 0;
}
