#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000000],maxs;
string b[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf(" %d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	    {
		    if(a[i]==a[j]&&i!=j) maxs=max(maxs,a[i]);
	    }
	}
	cout<<maxs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
