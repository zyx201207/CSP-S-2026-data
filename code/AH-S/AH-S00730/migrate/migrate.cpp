#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int t,n,d,x[N],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-4;i++)if(x[i+4]-x[i]<=d)ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
