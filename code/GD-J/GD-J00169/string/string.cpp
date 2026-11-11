#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a,ans;
char c;
string s;
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s=s+c;
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])
			ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
