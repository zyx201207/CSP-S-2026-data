#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s,s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
	}
	cout<<s<<endl;
	int ans=0,x=s.size()-1;
	for(int i=0,j=x;i<j;i++,j--)if(s[i]!=s[j]) ans++;
	cout<<ans;
	return 0;
}

