#include<bits/stdc++.h>
using namespace std;
int n;
int a[210000];
int ans;
char c[210000];
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	for(int i=0;i<s.size();i++){
		s2[i]=s[s.size()-i-1];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(ans%2==1){
			cout<<min(a[1],a[2]);
			return 0;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s2[i]) ans++;
	}
	cout<<ans/2;
	return 0;
}
