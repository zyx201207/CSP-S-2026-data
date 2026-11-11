#include<bits/stdc++.h>
using namespace std;
long long n,a,len,res = 0;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a>>c;
		for(int j = 1;j <= a;j++){
			s += c;
		}
		len += a;
	}
	for(int i = 0;i <= (len - 1) / 2;i++){
		if(s[i] != s[len - 1 - i]) res++;
	}
	cout<<res;
	return 0;
}
