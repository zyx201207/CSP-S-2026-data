#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
	}
	int ans=0;
	for(int i=0,j=n-1;i<n;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
