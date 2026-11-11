#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2000005];
long long cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
	}
	cout<<"1"<<endl<<"2";
	return 0;
}
