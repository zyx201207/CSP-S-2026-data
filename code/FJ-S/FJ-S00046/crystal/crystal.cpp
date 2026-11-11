#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=555555;
int a[N];
int n,m;
int q[N],w[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int sum=0,k=0;
			for(int j=i;j>=1;j--){
				int p=a[i]-a[j];
				if(sum+p>m){
					break;
				}
				sum+=p;
				k++;
			}
			ans=max(k,ans);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
//45pts
