#include<bits/stdc++.h>
using namespace std;
struct xl{
	int a;
	int t;
	int name;
}b[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[5005]={};
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].t;
		b[i].name=i;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<a[x]+a[y]+b[x].t+b[y].t;
	}
}
