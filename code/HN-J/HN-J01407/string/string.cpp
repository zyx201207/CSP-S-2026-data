#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N = 2e5+7;
int n;
int a[N],b[N],len,ans;
char c[N],d[N];
string s;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	for(int i=0;i<(s.size()>>1);i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
