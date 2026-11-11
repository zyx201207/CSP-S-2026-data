#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200008;
int a[N];
string c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	bool bl=true;
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			bl=false;
		}
	}
	if(bl==true){
		cout<<0;
		return 0;
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	if(bl==true){
		cout<<0;
		return 0;
	}
	ll num=0;
	ll ss=sqrt(s.size());
	for(ll i=0;i<=ss;i++){
		if(s[i]!=s[s.size()-i]){
			s[s.size()-i]=s[i];
			num++; 
		}
	}
	cout<<num;
	return 0;
}
