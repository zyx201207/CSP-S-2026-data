#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IN(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N=2e5+7;
int n;
int a[N];
int s[N];
char c[N];
string t=" ";
signed main(){
	IN("string");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			t+=c[i];
		}
	}
	int ans=0;
	int l=t.size()-1;
	for(int i=1;i<=l/2;i++){
		ans+=t[i]!=t[l+1-i];
	}
	cout<<ans;
	return 0;
}
