#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,ans;
string b,s,c,d;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a;
		cin >> b;
		for (int j=0;j<a;j++){
			s+=b;
		}
	}
	for (int i=s.size()/2-1;i>=0;i--){
		c+=s[i];
	}
	a=s.size()/2;
	if (s.size()%2==1) a++;
	for (int i=a;i<s.size();i++){
		d+=s[i];
	}
	if (c==d){
		cout << 0;
		return 0;
	}else{
		for (int i=0;i<c.size();i++){
			if (c[i]!=d[i]) ans++;
		}
	}
	cout << ans;
} 
