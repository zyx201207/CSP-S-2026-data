#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t>>t;
	cout<<t<<endl;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long a,b;
		cin>>a>>b;
		long long tmp=d/(b-a);
		cout<<max(0ll,n-tmp-tmp+1)<<' '<<n<<endl;
		for(int i=2;i<n;i++){
			scanf("%lld",&a);
		}
	}
	cout<<"???";
	return 0;
}

