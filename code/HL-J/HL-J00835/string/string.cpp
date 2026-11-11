#include<bits/stdc++.h>
using namespace std;
long long n,l,x,ans,a[400001];
char op;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>op;
		for(int j=1;j<=a[i];j++){
			s+=op;
		}
		l+=a[i];
	}
	s=" "+s;
	x=l/2;
	for(int i=1;i<=x;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}/*
3
2 a
2 b
1 c


2
2 a
3 a

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/