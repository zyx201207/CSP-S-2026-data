#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int tmp=n;
	for(int i=n;i>=1;i--){
		while(tmp>=2&&m>=a[i]-a[tmp-1]){
			m-=(a[i]-a[tmp-1]);
			tmp--;
		}
//		cout<<tmp<<" "<<m<<endl;
		ans=max(ans,i-tmp+1);
		m+=((ll)(i-tmp)*(a[i]-a[i-1]));
	}
	cout<<ans;
	return 0;
} 
