#include <bits/stdc++.h>;
using namespace std;
const long long N=2e6+10;
int n,a[N],d,c,t,cnt,p;
int main(){
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		if(n==1 || d==1){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	return 0;
}
