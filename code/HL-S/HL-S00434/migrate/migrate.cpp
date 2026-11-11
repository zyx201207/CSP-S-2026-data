#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N];
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int sum=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		int l=d/x;
		int p=l-1;
		int y=n/(2*l);
		sum+=p*y;
		cout<<0<<endl;
	}
	return 0;
}