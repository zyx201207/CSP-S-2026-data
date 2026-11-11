#include<bits/stdc++.h>
using namespace std;
const int maxn=600;
int n,m,c,d,q;
long long w[maxn],k[maxn];
struct N{
	long long id,t;
}a[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)cin>>a[j].id>>a[j].t;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y];
	}
	return 0;
}
