#include<bits/stdc++.h>
using namespace std;
string s;
long long len,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int i=0;i<a;i++)s+=c;
	}
	for(int i=0;i<len/2;i++)if(s[i]!=s[len-i-1])ans++;
	cout<<ans;
	return 0;
}
