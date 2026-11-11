#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,ans;
string s,b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
	cin>>a>>b;
		while(a--) s+=b;
		if(s.size()%2==0){
		    for(int i=0,j=s.size()-1;i<=s.size()/2-1;i++,j--){
				if(s[i]!=s[j]) ans++;
			}
		}else{
			for(int i=0,j=s.size()-1;i<=s.size()/2-1;i++,j--){
				if(s[i]!=s[j]) ans++;
			}
		}
	}
	cout<<ans/2;
	return 0;
}
