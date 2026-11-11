#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		int n;
		cin>>n;
		string s;
		for(int i=1;i<=n;i++){
			int a;
			char c;
			cin>>a>>c;
			for(int j=1;j<=a;j++){
				s+=c;
			}
		}
	//	cout<<s<<" ";
		int len=s.size();
		string s2;
		for(int i=(len-1)/2-1;i>=0;i--){
			s2+=s[i];
		}
	//	cout<<s2<<" ";
		int pos=0,ans=0;
		for(int i=(len-1)/2;i<=n;i++){
			if(s[i]!=s2[pos++]){
				ans++;
			}
		}
		cout<<ans;
	   return 0;
}

