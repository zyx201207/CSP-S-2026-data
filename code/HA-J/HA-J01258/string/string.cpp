#include<bits/stdc++.h>
using namespace std;
struct str{
	int n;
	string a;
}str [10001];
string b;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].n>>str[i].a;
	}
	if(n<=1) cout<<0;
	else if(n<=2){
			if(str[1].a==str[2].a) cout<<0;
			else cout<<min(str[1].n,str[2].n);
	}
	return 0;
}
