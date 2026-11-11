#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
int a[500005],n,m,ans[500005];
string s;
bool find(char a)
{
	if(s.empty()) return false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==a) return true;
	}
	return false;
}
void kards(char a)
{
	if(find(a)==false)
	{
		s+=a;
	}
	else
	{
		int p;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==a) 
			{
				p=i;
				break;
			}
		}
		string k="";
		if(p!=0)
		{
			for(int i=0;i<p;i++)
			{
				k+=s[i];
			}
		}
		k+=a;
		s=k;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]=0;
	}
	for(int i=1;i<=n;i++)
	{
		s="";
		for(int j=i;j<=n;j++)
		{
			char x=char(a[j]+'0');
			kards(x);
		}
		for(int j=1;j<=m;j++)
		{
			char y=char(j+'0');
			if(find(y)) ans[j]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<ans[j]<<" ";
	}
	return 0;
}
