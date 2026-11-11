#include<bits/stdc++.h>
using namespace std;
long long flag,n;
long long a,h;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		h+=a;
		for(int j=1;j<=a;j++)
			s[++flag]=c;
	}
	int ans=0;
//	for(int i=1;i<=h;i++) cout<<s[i];
	for(int i=1;i<=h;i++)
		if(s[i]!=s[h+1-i]) ans++;
	cout<<ans/2;
}
