#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0; cin>>n;
	string s;
	for(int k=1;k<=n;k++){
		int x;
                char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
			c++;
	}
	cout<<c;
}
