#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long n,a,len,k=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		while(a--)s+=c;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]+0!=s[len-i-1]+0)k++;
	}
	cout<<k;
	return 0;
}
