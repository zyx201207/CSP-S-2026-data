#include<bits/stdc++.h>
using namespace std;

long long n,sum,len;
long long a;
char c;
char s[100000005];
//map <long long,char> s;
//string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--)
			s[++len]=c;
	}
	for(int i=1;i<=len/2;i++) sum+=s[i]!=s[len-i+1];
	cout<<sum;
}
//aaabc
/*

 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
