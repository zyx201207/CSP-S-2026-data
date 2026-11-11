#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,w,ans,f;
char a;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>w>>a;
		while(w--){
			s+=a;
		}
	}
	f=s.size();
	for(int i=0;i<f;i++){
		if(s[i]!=s[f-i-1]){
			s[f-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
