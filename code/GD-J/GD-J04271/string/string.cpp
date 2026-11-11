#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;

const int N=2e5+5;

int n;

struct node{
	int len;
	char ch;
}a[N];
long long ans=0,gcd;
string str;
long long ispalidrome(string s){
	int i=0,j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j]) ans++;
		i++,j--;
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ch;
		gcd=(i==1?a[i].len:(long long)std::__gcd(gcd,1ll*a[i].len));
	}
	for(int i=1;i<=n;i++){
		str+=string(a[i].len/gcd,a[i].ch); 
	}
	
	cout<<ispalidrome(str)*gcd;
	
	
	
	
	
	return 0;
}
/*
3
2 a
2 b
1 c
*/

