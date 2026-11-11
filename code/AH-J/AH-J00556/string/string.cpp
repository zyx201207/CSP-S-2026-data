#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,x,cnt;
char y;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
