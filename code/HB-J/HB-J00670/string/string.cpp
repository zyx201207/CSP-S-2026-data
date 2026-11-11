#include<bits/stdc++.h>
using namespace std;
int a[100005],w=0;
 char b[100005];
	int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i]>>b[i];
}
	
	int st=1,he=n;
	while(st<he)
	{
		
			if(b[st]!=b[he])
			{
				if(a[st]>a[he])
				{
					w+=a[he];
					a[st]-=a[he];
					he--;
					
				}	
				else if(a[st]==a[he])
				{
					w+=a[st];
					he--;
					st++;
										

				}	
				else if(a[st]<b[he])
				{
					w+=a[st];
					a[he]-=a[st];
					st++;	
									

				}
			}
			else
			{
				if(a[st]>a[he])
				{
					a[st]-=a[he];
					he--;
				}	
				else if(a[st]==a[he])
				{
					he--;
					st++;
				}	
				else if(a[st]<b[he])
				{
					a[he]-=a[st];
					st++;
				}
			}
		}
	cout<<w;
	return 0;
}
