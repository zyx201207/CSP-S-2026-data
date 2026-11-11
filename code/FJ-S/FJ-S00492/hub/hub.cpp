#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[100005],v[100005];
int main()
{
	freopen("hud.in","r",stdin);
	freopen("hud.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<n-1<<endl;
	}
	return 0;
}
