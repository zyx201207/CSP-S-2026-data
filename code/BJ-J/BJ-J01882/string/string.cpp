#include <bits/stdc++.h>
using namespace std;
long long n;
int a;
string k;
long long num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n;
		char t;
		cin>>t;
		for(long long i=1;i<=n;i++){
			k+=t;
		}
	}
	string u=k;
	reverse(k.begin(),k.end());
	if(u==k){
		cout<<0;
		return 0;
	}
	long long len=k.length();
	len+=1;
	len/=2;
	for(long long i=len;i<(long long)k.length();i++){
		if(k[i]!=k[i-len]) num++;
	}
	cout<<num;
	return 0;
}
