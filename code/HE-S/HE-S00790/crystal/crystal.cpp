#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int y=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0;
	int c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=a[i-1];
		if(c==a[i])
		{
			sum++;
			y=a[i]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		c=min(c,a[i]);
		c++;
		if(c==a[i]){
			sum++;
			y=a[i]+1;
		}
		else if(m-c==a[i]||m>=0||a[i]==y){
			sum++;
			y=a[i]+1;
		}
		else
		{
			return 0;
		}
	}
	cout<<sum<<endl;
	return 0;
 } 
