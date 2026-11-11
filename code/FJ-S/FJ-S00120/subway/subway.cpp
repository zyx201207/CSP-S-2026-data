#include <bits/stdc++.h>
using namespace std;
struct subway{
	int w,t[505];
}sub[500005];
bool line[505][500005];
int c,n,m,d,q,k;
long long special_a(int x,int y){
	for(int i=1;i<=500;i++)
		if(line[i][x]&&line[i][y])
			return sub[x].w+sub[y].w+sub[x].t[i]+sub[y].t[i];
	for(int i=1;i<=1000;i++){
		if(sub[x].t[i]!=0){
			int z;
			for(int j=1;j<=1000;j++){
				if(line[i][j]!=0 && j!=x){
					z=j;
					break;
				}
			}
			return sub[x].w+sub[x].t[i]+special_a(z,y)-sub[z].w+sub[z].t[i];
		}
	}
}
long long special_b(int x,int y){
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>sub[i].w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>sub[a].t[i];
			line[i][a]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x,y;
		if(c<=11)
			cout<<special_a(x,y)<<endl;
		else
			cout<<(y-x)*sub[1].t[1]+sub[x].w+sub[y].w<<endl;
	}
	return 0;
}
