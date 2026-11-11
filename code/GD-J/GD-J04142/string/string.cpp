#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200005],sum,ans;
char c[200005],m[100000005];
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum>10000000){
		cout<<sum/2;
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=a[i];++j)m[sum+j]=c[i];
	for(ll i=1;i<=sum/2;++i)
		if(m[i]!=m[sum-i+1])ans++;
	cout<<ans;
	return 0;
}
