#include<bits/stdc++.h>

using namespace std;

#define int long long
int n,sum,max_a=-1e18,k;
char ch ;
map<char,int>tong;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> k >> ch ;
		tong[ch]+=k ;
		sum+=k ;
	}
	for(char i = 'a'; i <= 'z' ; (char)(i++)){
		max_a = max(max_a,tong[i]) ;
	}
	if(sum&1){
		cout << (sum-1)-max_a ;
	}else{
		cout << sum - max_a;
	}
	cout << '\n' ;
	return 0 ;
}
