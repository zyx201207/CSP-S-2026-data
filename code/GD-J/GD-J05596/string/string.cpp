#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}int c=0;
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			c++;
		}
	}cout<<c;
	return 0;
}
