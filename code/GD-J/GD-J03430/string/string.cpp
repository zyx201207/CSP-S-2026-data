#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long x,y,n,c;
char ch;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ch;
		for(int i=1;i<=x;i++)s+=ch;
	}
	y=s.size();
	for(int i=0;i<y/2;i++){
		if(s[i]!=s[y-1-i])c++;
	}
	cout<<c;
	return 0;
}
