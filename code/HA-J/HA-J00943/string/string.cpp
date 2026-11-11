#include<bits/stdc++.h>
using namespace std;
int n,a,si,ans,ans1,ans2;
string s,ts;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=s.size()-1;i>=0;i--) ts+=s[i];
	si=s.size()/2;
	for(int i=0;i<si;i++){
		if(s[i]!=ts[i]) ans1++;
	}
	for(int i=si;i<s.size();i++){
		if(s[i]!=ts[i]) ans2++;
	}
	ans=max(ans1,ans2);
	cout<<ans;
	return 0;
}
