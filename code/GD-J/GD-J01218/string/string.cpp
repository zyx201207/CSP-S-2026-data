#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=1e6+5;
int ans=0,n,a[maxn],sum;
string s;
char c[maxn];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	s=" ";
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];++j){
			s=s+c[i];
		}
	}
	for(int i=1;i<=sum/2;++i){
		if(s[i]!=s[sum-i+1]) ans++;
	}
	cout<<ans;
	return 0;
	//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b 1000000000
}
