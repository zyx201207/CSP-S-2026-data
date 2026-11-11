#include<bits/stdc++.h>
using namespace std;
long long a[500000],x,cnt,len;
int t2=0;
char b[500000];
int main()
{   freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
	}
	
	len=t/2;
	t2=t;
	if(t%2==0)
	{
		
		for(int i=1;i<=len;i++)
		{
			if(b[i]!=b[t2]){
	
					while(a[i]>0&&t2>=len){
						if(t2<len) break;
						if(a[i]>a[t2]) 
						{	
							a[i]-=a[t2];cnt+=a[t2];a[t2]=0;t2--;
						}
						else {
							a[t2]-=a[i];cnt+=a[i];a[i]=0;
							}
					}
			}
			if(b[i]==b[t2])
			{
				if(a[i]<=a[t2]){
					a[t2]-=a[i];a[i]=0;
					
				}
				else {
					a[i]-=a[t2];a[t2]=0;i--;t2--;
				}
			}

		}
	}
	else {
		for(int i=1;i<=len;i++)
		{
			if(b[i]!=b[t2]){
	
					while(a[i]>0&&t2>len){
						if(t2<=len) break;
						if(a[i]>a[t2]) 
						{	
							a[i]-=a[t2];cnt+=a[t2];a[t2]=0;t2--;
						}
						else {
							a[t2]-=a[i];cnt+=a[i];a[i]=0;
							}
					}
			}
			if(b[i]==b[t2])
			{
				if(a[i]<=a[t2]){
					a[t2]-=a[i];a[i]=0;
					
				}
				else {
					a[i]-=a[t2];a[t2]=0;i--;t2--;
				}
			}

		}
	}
	cout<<cnt;

	return 0;
}
