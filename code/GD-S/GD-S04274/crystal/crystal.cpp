#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],ans=0,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=a[i+1])
		{
			a[i]++;
			ans++;
		}
		else if(a[i]==a[i+1])
		{
			num+=2;
		}
		else if(ans==m)
		{
			break;
		}
	}
	cout<<num;
}
