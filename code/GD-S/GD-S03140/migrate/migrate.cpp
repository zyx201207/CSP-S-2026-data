#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		unsigned long long sum=2*9223372036854775807,di=0;
		vector<long long>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)sum=min(sum,1ull*(a[i]-a[i-1]));
		}
		if(sum>=d)cout<<0<<endl;
		else if(n<=3)cout<<0<<endl;
		else {
			if(d/2==sum)cout<<n-3<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2

5 2
1 2 3 4 5
*/
