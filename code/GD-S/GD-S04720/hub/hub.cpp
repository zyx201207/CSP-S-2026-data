#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Woai{
	char lneNO;
}deb[11725];
void zongzi(Woai flat){
	cout<<flat.lneNO<<endl;
	return;
}
ll c,t,n,k;
bool mapp[1001][1001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			ll u,v;
			cin>>u>>v;
			mapp[u][v]=1;
			mapp[v][u]=1;
		}
	}
	return 0;
}
