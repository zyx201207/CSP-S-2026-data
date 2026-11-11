#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int cnt=1,l=1;
	for(int i=2;i<=n;i++){
		ll sum=s[i-1]-s[l-1];
		ll tot=(i-l)*a[i]-sum;
		if(m>=tot) cnt=max(cnt,i-l+1);
		else l++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}