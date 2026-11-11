#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int h=1;h<=t;h++){
		long long n,d;
		cin>>n>>d;
		long long x[2000006];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<x[h]<<endl;
	}
	return 0;
}
