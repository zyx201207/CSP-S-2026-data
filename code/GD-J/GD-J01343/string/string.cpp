#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ans=0;
	string s=" ";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int l;
		cin>>l>>c;
		for(int j=1;j<=l;j++){
			s+=c;
		}
	}
	int l=s.size()-1;
	for(int i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
