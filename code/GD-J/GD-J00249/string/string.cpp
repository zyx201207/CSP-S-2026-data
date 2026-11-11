#include <bits/stdc++.h>
using namespace std;

int n,x,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int i=1;i<=x;i++)
			s+=c;
	}
	int len=s.length(),tmp=len;
	for(int i=0;i<=tmp/2;i++){
		if(s[i]==s[len-i-1])
			continue;
		else
			ans++; 
	}
	cout<<ans;
	return 0;
}
