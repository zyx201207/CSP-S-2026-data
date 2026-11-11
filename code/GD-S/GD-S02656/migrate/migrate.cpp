#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1||d<a[2]-a[1]||a[1]==a[2]){
			cout<<0<<'\n';
			continue;
		}
		int len=d/(a[2]-a[1]);
		len*=2;
		cout<<n-len+1<<'\n';
	}
	return 0;
} 

