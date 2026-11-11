#include<bits/stdc++.h>
using namespace std;

long long n, m;	
long long a[500007]{};
	
long long cnt[500007]{};
	
int main()
{
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m; 
	
	for(long long i=1;i<=n;i++)
	{
		
		cin>>a[i];
		
	}
	
	for(long long i=1;i<=n;i++)
	{
		
		vector<long long> q(n+1);
		long long flag1[500007]{};
		//long long flag2[500007]{};
		long long end=i-1;
		
		for(long long j=i;j<=n;j++)
		{
			
			//cout<<endl<<"j="<<j<<endl;
			
			if(flag1[a[j]]!=0)
			{
				
				//cout<<"flag="<<flag1[a[j]]+1<<" end="<<end<<endl;
				
				long long lsend=end;
				end=flag1[a[j]];
				
				//cout<<"end1="<<end<<endl;
				
				for(long long k=flag1[a[j]]+1;k<=lsend;k++)
				{
					
					//flag1[a[k]]=flag2[a[k]];
					//cout<<"q="<<q[k]<<endl;
					flag1[q[k]]=0;
					
				}
				
			}
			else
			{
				
				end++;
				
				//cout<<"end2="<<end<<endl;
				
				//cout<<endl<<end<<" "<<a[j]<<endl;
				
				q[end]=a[j];
				//flag2[a[j]]=flag1[a[j]];
				flag1[a[j]]=end;
				
			}
			
		}
		
		//cout<<endl;
		
		for(long long j=i;j<=end;j++)
		{
			
			//cout<<q[j]<<" ";
			cnt[q[j]]++;
			
		}
		
		//cout<<endl;
		
	}
	
	for(long long i=1;i<=m;i++)
	{
		
		cout<<cnt[i]<<" ";
		
	}
	
	return 0;
	
}
