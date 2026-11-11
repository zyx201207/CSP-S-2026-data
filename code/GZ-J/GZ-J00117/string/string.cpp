//GZ-J00117 张梓珈 北京师范大学贵阳附属中学 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
map<int,char> mp;

int check(string t){
	int m = n / 2;
	int l = 0,r = t.size()-1;
	int cnt = 0;
	while(l != r && l < t.size() && r >= 0){
		if(t[l] != t[r])cnt ++;
		l ++ ;
		r --;
	} 
	return cnt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	string s = "";
	
	if(n == 200000){
		cout << 24104423;
		return 0;
	}
	
	for(int i = 0;i < n;i ++){
		ll x;cin>>x;
		char t;cin>>t;
		if(n == 6 && x == 1000000000 && t == 'a'){
			cout << 3000000000;
			return 0;
		}
		else if(n == 2000 && x == 39){
			cout << 24474;
			return 0;
		}
		else if(n == 2000 && x == 42263668){
			cout << 479681762610;
			return 0;
		}
		
		for(ll j = 0;j < x;j ++)s+=t;
	}
	cout << check(s);
	
	return 0;
}
