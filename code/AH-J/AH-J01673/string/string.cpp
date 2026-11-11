#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005][3];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num1;char num2;
		cin>>num1>>num2;
		int sam=int(num2)-96;
		a[i][1]=num1,a[i][2]=sam;
	}
	int left=1,right=n,sum=0;
	while(!(left>right))
	{
		//cout<<left<<" "<<right<<endl;
		if(a[left][2]==a[right][2]&&a[left][1]==a[right][1]) 
			left++,right--;
  		if(a[left][2]!=a[right][2])
		{
			if(a[left][1]==a[right][1])
			{
				sum+=a[left][1];
		 	    left++,right--;
			}
	    	else
		    {
			    if(a[left][1]>a[right][1])
			    {
			    	a[left][1]-=a[right][1];
			    	right--;
				}
				else
			    if(a[left][1]<a[right][1])
			    {
			    	a[right][1]-=a[left][1];	
			    	left++;
				}				
		    }	
		}
		else
		{
			 if(a[left][1]>a[right][1])
			 {
			 	a[left][1]-=a[right][1];
			 	right--;
			 }
			 else
			 if(a[left][1]<a[right][1])
			 {
			 	a[right][1]-=a[left][1];
			 	left++;
			 }
		}	

	}
	cout<<sum<<endl;
	return 0;
}
