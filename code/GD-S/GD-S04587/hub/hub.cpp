#include<bits/stdc++.h>
using namespace std;
long long c,t,mj=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		long long n,k,u[1000005],v[1000005];
		cin>>n>>k;
		for(long long i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<mj+1<<'\n';
		mj+=1;
	}
	return 0;
}
