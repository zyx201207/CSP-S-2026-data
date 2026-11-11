#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int w[500005];
struct runt{
	int s,e;
}r[100001];
struct nn{
	int a,t;
}a[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki=0;cin>>ki;
		for(int i=1;i<=ki;i++){
			cin>>a[i].a>>a[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].s>>r[i].e;
	}
	for(int i=1;i<=q;i++){
		
	}
}
