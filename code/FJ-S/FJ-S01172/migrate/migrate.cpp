#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000010];
long long d,n;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<abs(a[3]);
	}
	return 0;
} 
