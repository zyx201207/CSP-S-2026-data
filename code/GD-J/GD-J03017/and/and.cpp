#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%lld",&a[i]);
		ans=max(ans,a[i]);
	}
	if(m==1) cout<<ans;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) continue;
				ll qwe=a[i]&a[j];
				sum=max(sum,qwe);
			}
		}
		cout<<sum;
	}
	return 0;
} 
