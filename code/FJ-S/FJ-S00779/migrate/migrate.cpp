#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(a[2]-a[1]>=d) cout<<0;
		else{
			d/=a[2]-a[1];
			d=d*2;
			if(d>n) cout<<0;
			else cout<<n-d+1;
		}
		cout<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
