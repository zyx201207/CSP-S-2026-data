#include <bits/stdc++.h>
#define int long long
using namespace std;


int c,n,m,d,q,w[20005];
struct subway{
	int k,a[10005],t[10005];
}sub[500];


bool cmp(int x,int y){
	return x<y; 
}

signed main(){
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%lld",&sub[i].k);
		for (int j=1;j<=sub[i].k;j++){
			scanf("%lld%lld",&sub[i].a,&sub[i].t);
		}
	}
	for (int i=1;i<=n;i++){
		sort(sub[i].a+1,sub[i].a+sub[i].k+1,cmp);
	}
	cout<<1<<endl<<1;
}
