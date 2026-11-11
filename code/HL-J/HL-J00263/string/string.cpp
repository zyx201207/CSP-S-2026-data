#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long a,cnt;
char ch;
string s;
bool f=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(unsigned long long i=1;i<=n;i++){
		cin>>a>>ch;
		for(unsigned long long i=1;i<=a;i++)s+=ch;
	}
	unsigned long long mid=s.size()/2;
	unsigned long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])cnt++;
		l++,r--;
	}cout<<cnt;
	return 0;
}
