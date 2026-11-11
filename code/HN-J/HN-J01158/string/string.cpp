#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		int b;
		cin>>b>>a;
		len+=b;
		while(b--){
			s+=a;
		}
	}
//	cout<<s<<" "<<len<<endl;
	for(int i=0;i<=(len)/2;i++){
//		cout<<i<<" "<<len-i-1<<endl;
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

