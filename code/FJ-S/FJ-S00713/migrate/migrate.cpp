#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		int n,d;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(a[n]-a[1])%(n)/(d)<<endl;
	}
	
	return 0;
}


