#include <bits/stdc++.h>
using namespace std;
long long a[200010];
string s[200010];
string tentotwo(int n){
	string b="";
	while(n!=0){
		b+=char(n%2+'0');
		n/=2;
	}
	string a="";
	for(int i=b.length()-1;i>=0;i--){
		a+=b[i];
	}
	return a;
}
int twototen(string n){
	long long k=0,j=0;
	for(int i=n.length()-1;i>=0;i--){
		int l=n[i]-'0';
		k+=l*pow(2,j);
		j++;
	}
	return k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=tentotwo(a[i]);
	}
	sort(s,s+n);
	int l=twototen(s[n-1]);
	for(int i=n-2;i>=n-m;i--){
		l=l&twototen(s[i]);
	}
	cout<<l;
	return 0;
}
