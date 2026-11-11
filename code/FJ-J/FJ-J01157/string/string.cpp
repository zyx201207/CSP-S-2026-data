#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b;
    char c;
    cin>>a;
    int k=0;
    string s="";
    for(int i=1;i<=a;i++){
    	cin>>b>>c;
    	k+=b;
    	s+=c;
	}
	
	int ans=0;
	
	for(int i=1;i<=k;i++){
		for(int j=k;j>=1;j--){
		if(s[j]!=s[i]){
			s[j]=s[i];
			ans++;
		}
	}
	
	}
	cout<<ans/2;
	return 0;
}

