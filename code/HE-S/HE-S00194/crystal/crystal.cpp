#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long s[N];
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		long long num=(s[i]+m)/a[i];
		if(num>i) num=i;
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
