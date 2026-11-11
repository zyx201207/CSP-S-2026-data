#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	cin>>n>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<(n-d-1)<<endl;
	}
	return 0;
}
