#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
string s[N],ans="111111111111111111111111111111";
string rjz(long long x){
	string s1="",s2="";
	while(x>0){
		s1+='0'+x%2;
		x/=2;
	}
	return s1;
}
string awy(string x,string y){
	int num=min(x.size(),y.size());
	string s1="";
	for(int j=0;j<num;j++){
		if(x[j]==y[j]&&x[j]=='1')s1+='1';
		else s1+='0';
	}
	return s1;
}
long long sjz(string x){
	int w=1;
	long long num=0;
	for(int j=0;j<x.size();j++){
		num+=(x[j]-'0')*w;
		w*=2;
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=n-m+1;i<=n;i++)s[++cnt]=rjz(a[i]);
	for(int i=1;i<=cnt;i++)ans=awy(ans,s[i]);
	cout<<sjz(ans);
	return 0;
} 
