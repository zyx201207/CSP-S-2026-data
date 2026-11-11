#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int w[5000005];
struct Node{
	int a,t;
};
Node s[5000005][5005];
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int j=1;j<=q;j++){
		cin>>k;
		for(int i=1;i<=(k*2);i++){
			cin>>s[i][j].a>>s[i][j].t;
		}
	}
	for (int j=1;j<=q;j++){
		cin>>x>>y;
		cout<<x*y<<endl;
	} 
	return 0;
}  
