#include<bits/stdc++.h>
using namespace std;
int n,vis[500005],m,a[500005],b[500005],visl,t[300005];
char flag;
string s;
int main(){
	freopen(card,r,stdin);
	freopen(card,w,stdout);
	cin>>n>>m;
	for(int i = 1;i<=m;i++)
	{
		cin>>a[i];
		
	}
	for(int i = 2;i<=m;i++)
	{
		if(a[i]!=a[i-1]){
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<n;
		return 0;
	}
	for(int i = 1;i<m;i++)
	{
		t[a[i]]++;
	}
	for(int i = 1;i<m;i++)
	{
		if(t[i]!=0){
			cout<<0;
		}
	}
	cout<<n;
	return 0;
} 
