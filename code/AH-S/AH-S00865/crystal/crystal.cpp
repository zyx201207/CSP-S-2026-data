#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long a[M],m,s[M];
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1,j=0;i<=n;i++){
		if(m>=(i-j)*a[i]-s[i]+s[j]){
			ans=max(ans,i-j);
		}
		else {
			while(m<(i-j)*a[i]-s[i]+s[j]&&j<i)j++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
