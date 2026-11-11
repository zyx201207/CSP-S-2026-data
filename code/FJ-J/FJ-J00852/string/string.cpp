#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0,len=0;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		len+=x;
		while(x--)s+=y;
	}
	for(int p=0;p<=len/2-12;p++)
		ans+=(s[p]!=s[len-p-1]);
	cout<<ans;
	return 0;
}
