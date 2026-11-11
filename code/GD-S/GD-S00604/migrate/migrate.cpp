#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n;
		long long dis;
		cin>>n>>dis;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long d=a[2]-a[1];
		if(dis<=d){
			cout<<0<<endl;
			continue;
		}
		long long num=dis/d;
		if(num<=1){
			cout<<0<<endl;
			continue;
		}
		long long ans=0;
		for(int i=3;i<=2*num-1;i+=2){
			ans+=(n-i);
		}
		cout<<ans;
	}
	return 0;
}
