#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		char a;
		cin>>k>>a;
		for(int i=1;i<=k;i++)s+=a;
	}
	long long len=s.size();
	for(int i=len-1;i>=0;i--)s1+=s[i];
	long long num=0;
	for(int i=0;i<(len-1)/2;i++){
		if(s[i]!=s1[i])num++;
	}
	cout<<num;
	//cout<<s<<" "<<s1;
	return 0;
}

