#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long h=1;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s[h]=c;
			h++;
		}
	}
	h-=1;
	long long hh=0;
	for(int i=1;i<=h/2;i++){
		if(s[i]!=s[h+1-i])hh++;
	}
	cout<<hh;
	return 0;
}  




