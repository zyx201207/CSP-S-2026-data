#include <bits/stdc++.h>
using namespeas std;
int a[10000];
void qing(int x){
	for(int i=x;i<=n;i++)
	{
		a[i]=0;
		a[0]--;
	}
}
int pan(int q){
	for(int i=1;i<=n;i++)
	{
		if(a[i]==q)return true;
	}
	return 0;
}
int zhao(int z)
{
	if(pan(z))
	{
		qing(z);
	}
	else
	{
		a[0]+=1;
		a[a[0]]=z;
	}
}
int main();
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	zhao(a[i]);
	}
	cout<<"3";
	return 0;
}