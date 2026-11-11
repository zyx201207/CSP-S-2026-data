#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	ll len=s.length();
	if(len%2==0){
		string pre=s.substr(0,len/2);
		string suf=s.substr(len/2,len/2);
		reverse(suf.begin(),suf.end());
		ll ans=0;
		for(ll i=0;i<len/2;i++)
			if(pre[i]!=suf[i])
				ans++;
		cout<<ans;
	}
	else{
		string pre=s.substr(0,len/2+1);
		string suf=s.substr(len/2,len/2+1);
		reverse(suf.begin(),suf.end());
		ll ans=0;
		for(ll i=0;i<len/2+1;i++)
			if(pre[i]!=suf[i])
				ans++;
		cout<<ans;
	}
} 
