#include<bits/stdc++.h>
using namespace std;
long long l,ans;
long long a[200005],sum[200005];
char c[200005];
char s[100000002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; l+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1,j=1;i<=l&&j<=n;i++){
		if(i>sum[j]){
			j++;
		}
		s[i]=c[j];
	}
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
