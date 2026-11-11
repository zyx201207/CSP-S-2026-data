#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m,a[10005],s,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=n/2;i>=1;i--)
    {
    	
    	if(m>=0)
    	{
    		s+=a[i];
    		
    		m-=a[n/2+1]-s;
    		sum++;
    		
    		s=0;
		}
	}
	cout<<sum+1;

	
	return 0;
} 
