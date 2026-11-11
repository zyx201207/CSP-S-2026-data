#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=0;
long long m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	int p=1;
	for(int i=1;i<=n;++i){
		while(m<(i-p+1)*a[i]-(s[i]-s[p-1])) ++p;
		ans=max(ans,i-p+1);
	}
	cout<<ans;	
	return 0;
}
