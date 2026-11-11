#include <iostream>
using namespace std;
const int N=1e7+10;
long long n,m,a[N];
long long ans=-0x3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		for(int j=i+1;j<=i+m-1;j++){
			for(int z=j+1;z<=n;z++){
				ans=max(ans,(a[i]&a[j])&a[z]);
			}
		}
	}
	cout<<ans;
	return 0;
}
