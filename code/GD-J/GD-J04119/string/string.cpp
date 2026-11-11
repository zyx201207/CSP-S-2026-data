#include<bits/stdc++.h>
using namespace std;
long long n,s;
char c;
bool check(string sq){
	long long l=0,r=sq.size()-1;
	while(l<r){
		if(sq[l]!=sq[r]){
			return 0;
		}
		l++,r--;
	}
	return 1;
}
long long recheck(string sq){
	long long l=0,r=sq.size()-1,cnt=0;
	while(l<r){
		if(sq[l]!=sq[r]){
			cnt++;
		}
		l++,r--;
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string st;
	while(n--){
		cin>>s>>c;
		for(long long i=1;i<=s;i++){
			st+=c;
		}
	}
	if(check(st)){
		cout<<0;
		return 0;
	}else{
		cout<<recheck(st);
	}
	return 0;
}
