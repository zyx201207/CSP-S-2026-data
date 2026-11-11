#include<bits/stdc++.h>
using namespace std;
string sw(string s){
	string ans;
	for(int i=s.length()-1;i>=0;i--)ans+=s[i];
	return ans;
}long long toint(string s){
	long long ans=0;
	for(int i=0;i<s.length();i++){
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
}string to2(int n){
	string ans;
	while(n>0){
		char c=(n%2)+'0';
		ans+=c;
		n/=2;
	}return sw(ans);
}long long count1(string s){
	long long ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1')ans++;
	}return ans;
}struct num{
	long long two;
	long long n1;
	long long n;
	long long zh;
};
bool cnt(num a,num b){
	return a.zh>b.zh;
}long long n,m;
num a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].n;
		a[i].two=toint(to2(a[i].n));
		a[i].n1=count1(to2(a[i].n));
		a[i].zh=a[i].two+a[i].n1;
	}sort(a+1,a+n+1,cnt);
	long long ans=a[1].n;
	for(int i=2;i<=m;i++)ans&=a[i].n;
	cout<<ans;
}
