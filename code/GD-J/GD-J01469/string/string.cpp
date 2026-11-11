#include<bits/stdc++.h>
using namespace std;
long long n ,sum;
string s="";
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n ;
	for(long long i = 1 ; i <= n ; i ++){
		cin >> a[i] >> c[i] ;
	}
	for(long long i = 1 ; i <= n ; i ++){
		for(long long j = 1 ; j <= a[i] ; j ++){
			s+=c[i];
		}
	}	
	long long len=s.size();
	s=" "+s;
	for(long long i = 1 ; i <= len/2 ; i ++){
		if(s[i]!=s[len+1-i])sum++;
	}
	cout << sum << endl;
	return 0;
}
