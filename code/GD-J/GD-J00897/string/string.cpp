#include<bits/stdc++.h>
using namespace std;
char b[500005];
long long a[500005],s;
int n;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);	
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i<j;)
	{
	    if(b[i]!=b[j])
		{
			s+=min(a[i],a[j]);
		}		
		if(a[i]==a[j])i++,j--;
		else 
		{
			if(a[i]>a[j])	    
		    {
			  a[i]=a[i]-a[j];
			  j--;
		    }
		    else
		    {
			  a[j]=a[j]-a[i];
			  i++;
		    }
		}
	}
	cout<<s;
	return 0;
} 
