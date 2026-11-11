#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--)s=s+c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
