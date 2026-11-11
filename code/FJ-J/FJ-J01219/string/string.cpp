#include <bits/stdc++.h>
using namespace std;
long long n,len=0;
long long a[2000005];
char s[2000005];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			b+=s[i];
		}
	}
	long long num=0;
	for(int i=1;i<=len/2;i++){
		if(b[i-1]!=b[len-i]) {
			num++;
		}
	}
	cout<<num;
	return 0;
}
