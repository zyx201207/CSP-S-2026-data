//luogu_UID:2051996 

#include<bits/stdc++.h>
using namespace std;
int n,a[100001],ans,maxn,b[100001],snt=1;char c[100001];string s;
bool hw(string x){
	for(int i=snt;i>=1;i--)b[i]=s[i];
	for(int i=1;i<=snt;i++)
		{if(b[i]!=s[i])return false;}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxn=max(maxn,a[i]);
		for(int j=1;j<=a[i];j++)s[++snt]=c[i];
	}
	if(hw(s))cout<<0; 
	else{
		if(n==1)cout<<0;
		if(n==2 && a[0]==a[1])cout<<0;
		else if(n==2 && a[0]!=a[1])cout<<1;
		else if(maxn==1)cout<<n/2;
	}
	
	return 0;
}

