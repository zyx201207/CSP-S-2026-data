//GZ-S00135 胡睿晨 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
long long u[2000010],v[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
	}
	return 0;
}
