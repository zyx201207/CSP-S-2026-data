#include<bits/stdc++.h>

using namespace std;
bool huiwen(string s){
	string k="";
	for(int i=s.size()-1;i>=0;i--){
		k+=s[i];
	}
	if(k==s)return 1;
	else return 0;
}
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		f=max(f,a[i]);
	}
	if(f<=500){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	if(huiwen(s)){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<=s.size()/2+1;i++){
		if(s.size()%2==0){
			if(s[i]!=s[s.size()-i+1]){
			ans++;
		}
		}
		else {
			if(s[i]!=s[s.size()-i]){
			ans++;
		}
		}
	}
	cout<<ans;
	}
	return 0;
}
