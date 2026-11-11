#include<bits/stdc++.h>
using namespace std;
long long n,l[200010],a[200010],ans,k=1,r;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>l[i];
		a[i+1]=a[i]+l[i];
		cin>>s[i];
	}
	r=n;
	for(long long i=1;i<=a[n+1]/2;i++){
		long long j=a[n+1]+1-i;
		if(i>a[k+1])  k++;
		if(j<=a[r])  r--;
		if(s[k]!=s[r])  ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
