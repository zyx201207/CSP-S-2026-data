#include<bits/stdc++.h>
using namespace std;
long long n,len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char a;
		cin>>x>>a;
		len+=x;
		ans+=x;
		for(int i=1;i<=x;i++) s+=a;
	}
	len=len/2-1;
	long long sum=0;
	for(int i=0;i<=len;i++){
		if(s[i]!=s[ans-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
