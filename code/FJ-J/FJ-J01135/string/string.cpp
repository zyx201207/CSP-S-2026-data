#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string l;
		int p;
		cin>>p>>l;
		for(int j=1;j<=p;j++)s+=l;
	}
	if(s.size()==1){
		cout<<0;
		return 0;
	}
	for(int l=0;l<s.size();l++){
		int r=s.size()-1-l;
		if(l>=r)break;
		if(s.size()%2==1){
			if(s[l]==s[r]&&r-l>1)cnt++;
		}else if(s[l]==s[r])cnt++;
	}
	if(s.size()%2==1)cout<<(s.size()-1)/2-cnt;
	else cout<<s.size()/2-cnt;
	return 0;
}
