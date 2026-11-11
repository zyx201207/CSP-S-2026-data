#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505];
map<int,int>m,m2,m3,m4;
struct _{
	int a[5],b[5];
};
long long qqq(int x,int z,long long qwe){
	if(x==z)return qwe;
	long long qwr=b[m[x]].b[m4[x]];
	if(m2.count(x))qwr+=
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	if(c>=7&&c<=11){
		_ b[2005];
		for(int i=1;i<=n;i++){
			int u;
			cin>>u;
			for(int j=1;j<=u;j++){
				cin>>b[i].a[j]>>b[i].b[j];
				if(m.count(a[j]))m2[a[j]]=i,m3[a[j]]=j;
				else m[a[j]]=i,m4[a[j]]=j;
			}
		}
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			
			cout<<a[u]+qwe+a[v]<<"\n";
			qwe=0;
		}
	}
	return 0;
}

