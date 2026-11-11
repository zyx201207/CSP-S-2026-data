#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,fa[20050],asw;
long long w[2050],//地铁口走到站厅需要的时间
          a[2050],//经过的地铁站
          k[2050],//经过的地铁站数
          t[250][100];//站厅走到站台的时间
/*int find(int x){
	if(fa[x]!=x) fa[x]=find[fa[x]];
	return fa[x];
}
void com(int x,int y){
	find(x)=find(y);
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int ls;
			if(j%2==1){
				cin>>a[(i+1)/2];
				fa[a[(i+1)/2]]=i;
			}
			else cin>>t[i/2][i];
		}
	}
	while(q--){
		cin>>x>>y;
		asw+=w[x]+t[x];
		asw+=w[y]+t[y];//必须时间
		if(fa[x]==fa[y]){
			cout<<asw;
			continue;
		}
		
	}
    return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3*/
