#include<bits/stdc++.h>
using namespace std;
#define int long long 
main(){
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
	int ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

