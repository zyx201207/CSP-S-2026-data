#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,len,ans;string s="";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;long long cnt;char ch;
	for(long long i=1;i<=n;++i){
		cin>>cnt>>ch;
		for(long long j=1;j<=cnt;++j)
			s=s+ch;
		len+=cnt;
	}
//	cout<<s<<" "<<len<<endl;
	for(long long i=0;i<len/2;++i)
		if(s[i]!=s[len-i-1]) ans++;
	cout<<ans;
	return 0;
}
