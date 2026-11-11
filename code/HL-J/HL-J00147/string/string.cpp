#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5;
int m,a[N],tong[26];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>m;
    string s=" ";
    int n=0;
    for(int i=1;i<=m;i++){
    	char c;
		cin>>a[i]>>c;
    	n+=a[i];
		for(int j=1;j<=a[i];j++){
    		s+=c;
		}
	}
//	cout<<s;
	int ans=0;
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
