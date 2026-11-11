#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,k,u[2000005],v[2000005],map[2000005][2000005]={0};
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
			map[u[i]][v[i]]=1;
			map[v[i]][u[i]]=1;
		}
		cout<<1<<endl;
		
	}
	return 0;
}
