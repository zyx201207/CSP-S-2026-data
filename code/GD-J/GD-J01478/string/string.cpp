#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,w,k,a[N];
string s;
char b[N];

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie(0);
	
	cin>>n;
	char ch;
	bool f=true;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		m+=a[i];
		if(i==1)ch=b[i];
		if(ch!=b[i])f=false;
		if(i==1)k=a[1];
		else k=gcd(k,a[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]/=k;
	}
	m/=k;
	if(f==true){
		cout<<0;
		return 0;
	}
	s+=" ";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=a[i];++j)s+=b[i];
	}
	for(int i=1;i<=m/2;++i){
		if(s[i]!=s[m-i+1]){
			w++;
		}
	}
	cout<<w*k;
	return 0;
}
