#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int w[N];
struct node {
	int a,t;
}e[N];
struct node2{
	int x,y;
}e2[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	while(n--){
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=2*k;i++){
		cin>>e[i].a>>e[i].t;	
	} 
	for(int i=1;i<=q;i++){
		cin>>e2[i].x>>e2[i].y;
	}
	
}
}
