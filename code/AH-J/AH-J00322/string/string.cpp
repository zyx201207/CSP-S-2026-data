#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int hw(string s){
	string a="";
	for(int i=s.size()-1;i>=0;i--){
		a+=s[i];
	}
	if(s==a){
		return 0;
	}
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=a[i]){
			s[i]=a[i];
			a[s.size()-i-1]=s[i];
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		int ans=a[i];
		while (ans>0){
			s+=c[i];
			ans--;
		}
	}
	cout<<hw(s);
	return 0;
}
