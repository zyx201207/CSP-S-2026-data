#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char a;
		cin>>t>>a;
		for(int j=1;j<=t;j++){
			s+=a;
		}
	}
	int l=0,r=s.size()-1;
	while (l<r){
		if(s[l]!=s[r])cnt++;
		l++;
		r--;
	}
	cout <<cnt;
	return 0;
}
