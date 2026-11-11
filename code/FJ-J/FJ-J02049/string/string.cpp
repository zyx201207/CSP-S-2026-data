#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt;
string s,l;
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--){
		cin>>x>>s;
		while (x--){
			l+=s;
		}
	}
	long long len=l.length();
	for (long long i=0;i<len/2;i++){
		if (l[i]!=l[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
