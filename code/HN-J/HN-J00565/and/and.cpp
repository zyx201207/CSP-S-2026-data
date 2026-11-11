#include<bits/stdc++.h>
using namespace std;
string jz(int a){
	string s;
	while(a>=0) s+=a%2+'0'; 
	reverse(s);
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,sd,s;
	//vector<vector<string>> f;
	cin>>n;
	cin>>s;
	for(int i=2;i<=n;i++){
		cin>>sd;
		s&=sd;
	//cin>>sd,f[jz(sd).size()][]=jz(sd);
	}
	cout<<jz(s);
	return 0;
}
