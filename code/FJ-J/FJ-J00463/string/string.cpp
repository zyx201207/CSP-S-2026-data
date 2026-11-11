#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,num,sum;
char ch;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ull i=1;i<=n;i++){
		cin>>num>>ch;
		for(ull j=1;j<=num;j++){
			a=a+ch;
		}
	}
	ull len=a.length();
	ull cnt=0;
	for(ull i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
