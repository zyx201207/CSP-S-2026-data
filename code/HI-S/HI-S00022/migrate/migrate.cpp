#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,d,ans=0;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+3<=n;i++){
			int sum=0;
			for(int j=i+1;j<=i+2;j++){
				if(abs(a[j]-a[i])<=d&&abs(a[i+3]-a[j])<=d){
					sum++;
				}
			}
			if(sum==2)ans++;
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
