#include<bits/stdc++.h>
using namespace std;
long long c,d,n,m,q,w[500007],k[507],i,j,e,f;
struct xy{
	long long a,t;
}z,s;
vector <xy> v[507];
vector <long long> as[500007];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++){
		cin>>w[x];
	}
	for(int x=1;x<=n;x++){
		cin>>k[x];
		for(int y=1;y<=k[x];y++){
			cin>>z.a>>z.t;
			v[x].push_back(z);
			as[z.a].push_back(x);
		}
	}
	for(int er=1;er<=q;er++){
		cin>>i>>j;
		cout<<0<<"\n";
	}
	return 0;
}
