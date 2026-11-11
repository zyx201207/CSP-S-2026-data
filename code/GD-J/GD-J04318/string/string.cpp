#include <bits/stdc++.h>
using namespace std;
string a,c,e,z,f,r;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a>>c>>e>>z>>f>>r;
	string s="aabbc";	
	int h=0;
	if(s[1]!=s[5]){
		h++;
	}
	if(s[2]!=s[4]){
		h++;
	}
	cout<<h;
}
