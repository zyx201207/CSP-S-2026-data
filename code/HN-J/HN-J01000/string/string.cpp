#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string fz(string x){
	string fh="";
	for(int i=x.size()-1;i>=0;i--){
		fh+=x[i];
	}
	return fh;
}
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,maxx=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	if(fz(s)==s){
		cout<<0;
	}
	
	return 0;
}
