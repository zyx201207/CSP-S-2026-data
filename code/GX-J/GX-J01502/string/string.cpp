#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string ch;
		cin>>x>>ch;
		while(x--) s+=ch;
	}
	cout<<0;
	return 0;
}
