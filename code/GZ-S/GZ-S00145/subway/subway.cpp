//GZ-S00145 周小晰 贵阳一中 
#include<bits/stdc++.h>
using namespace std;
long long w[100005],s1[100005],s2[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
		s1[i]=s1[i-1]+w[i];
	}
	for(int i = 1,k,a,b,c,d;i<=n;i++){
		cin>>k>>a>>b>>c>>d;
		s2[a]=b;
		s2[c]=b+d;
	}
	for(int i = 1,x,y;i<=q;i++){
		cin>>x>>y;
		if(s2[y]<1e18 &&s2[x]<1e18)cout <<s1[y]+s2[y]<<endl;
	}
}
//T2 Dijkstra 关键于建边
//45min 没思路，跳T3 
 
