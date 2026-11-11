#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans=-1;
string zhuan2(ll x){
	string shu="";
	ll temp=x;
	while(temp!=0){
		shu+=((temp%2)+'0');
		temp/=2;
	}
	return shu;
}
ll zhuan10(string x1){
	ll de=0,ji=1;
	for(int i=0;i<x1.size();i++){
		if(x1[i]=='1') de+=ji;
		ji*=2;
	}
	return de;
}
string pan(string s1,string s2){
	int len;
	string te1=s1,te2=s2,de1="",de2="";
	len=min(te1.size(),te2.size());
	for(int i=0;i<len;i++){
		if(te1[i]=='1'&&te2[i]=='1') de1+='1';
		else de1+='0';
	}
	while(de1[len-1]=='0') len--;
	for(int i=0;i<len;i++) de2+=de1[i];
	return de2;
}
void dfs(int num,int poin,string dan){
	if(num==m){
		ans=max(ans,zhuan10(dan));
		return;
	}
	for(int i=poin+1;i<=n;i++){
		dfs(num+1,i,pan(dan,zhuan2(a[i])));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		dfs(1,i,zhuan2(a[i]));
	}
	cout<<ans;
	return 0;
}
