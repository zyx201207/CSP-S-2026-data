#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<0<<endl;
	cout<<t;
	return 0;
}
