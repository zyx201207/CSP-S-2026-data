//GZ-S00135 胡睿晨 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long tmp=0;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			if (x[i]-x[1]>=d && x[tmp]-x[1]<d)
				tmp=i;
		}
		cout<<tmp<<'\n';
	}
	return 0;
}
