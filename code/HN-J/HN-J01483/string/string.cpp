#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],sum=0,ans=0;
char c;
string s,l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	if(s.size()%2!=0){
		for(int i=s.size()-1;i>s.size()/2;i--){
			r+=s[i];
		}
	}
	else{
		for(int i=s.size();i>s.size()/2-1;i--){
			r+=s[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(r[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


