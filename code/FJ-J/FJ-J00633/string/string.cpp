#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		char a;
		int l;
		cin>>l>>a;
		for(int j=1;j<=l;j++){
       	    s+=a;
    	}
	}
	int ans=0;
	int xz=s.size()/2;
	if(s.size()%2==0){
		xz++;
	}
	for(int i=0;i<=xz;i++){
		
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
