#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i=0,ans=0;
	string s;
	cin>>n;
	while(n--) {
		int a;
		char c;
		cin >>a>>c;
		for(int j=0;j<a;j++){
			s[i]=c;
			i++;
		}
	}
	for(int j=0;j<s.size()/2;j++)	{
		if(s[j]!=s[n-j]) ans++;
	}
	cout<<ans;	
	return 0;
}	
