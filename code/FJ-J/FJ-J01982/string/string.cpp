#include<bits/stdc++.h>
using namespace std;
bool f(string s){
	for(int i=0,j=(int)s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])return false;
	}
	return true;
}
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++)s+=c;
	}
	if(f(s)){
		cout<<0<<endl;
		return 0;
	}
	int ans=0;
	for(int i=0;i<(int)s.size();i++){
		for(int j=i+1;j<(int)s.size();i++){
			if(f(s.substr(i,j-i-1))){
				int cnt=0;
				for(int l=0,r=(int)s.size()-1;l<i;l++,r--){
					if(s[l]!=s[r])cnt++;
				}
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans;
	return 0;
}
