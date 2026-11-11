#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005];
ll ans,len;
string s; 
signed main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		len+=a[i];
		for(int j=1;j<=a[i];j++)
			s+=c;
	}
//	cout<<s<<"\n";
	for(int i=0;i<floor(len/2.0);i++){
		if(s[i]!=s[len-i-1])ans++,s[i]=s[len-i-1];
	}
	cout<<ans;
	return 0;
} 
//Trick||Treat!
