#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		a[i]=b;
		
	}
	sort(a+0,a+n);
	for(int i=0;i<n;i++){
	if(a[i]==a[i+1])
		{
			cnt++;
		}
	}
	if(n%2==0)
{
	for(int i=0;i<n/2;i++)
	{
	while(a[i]==a[n/2] && m!=0)
	{
	a[i]++;
	m--;
    }
    cnt++;
	}
}
    else
    {
    	for(int i=0;i<n/2+1;i++)
    	{
    	while(a[i]==a[n/2+1] && m!=0)
	{
	a[i]++;
	m--;
    }
    cnt++;	
		}
	}
	
	cout<<cnt;
	return 0;
 } 
