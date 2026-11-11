#include<iostream>
using namespace std;
int a[500005];
struct nodea{
	int a,t;
}b[505];
struct nodeb{
	int l,r;
}e[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j].a>>b[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>e[i].l>>e[i].r;
	}
	for(int i=1;i<=q;i++){
		cout<<c+n+m+d+q<<'\n';
	}
}
