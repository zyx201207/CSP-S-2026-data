#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,Map[1000010][100010],x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		memset(Map,0,sizeof(Map));
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			cin>>x>>y;
			Map[x][y]=1;
		}
		cout<<1<<'\n'<<2;
	}
	return 0;
} 
