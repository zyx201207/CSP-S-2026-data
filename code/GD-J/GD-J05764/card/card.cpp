#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	//freopen("card.in","r",stdin);
	// freopen("card.out","w",stdout);
	string a;
	long long n,m;
	cin >> n >> m;
	int ji[n+5] ={};
	int b[n+5]={};
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		
	}
 
	
	for(int i = 1;i<= n;i++)
	{ 
		for(int  j =  i ;j<= n;j++ )
		{
			
			ji[a[j]-'0']++;
			if(ji[a[j]-'0'] > 1)
			{
				int h = j;
			
				while(h > 0)
				{
					h--;
					if(a[h] == a[j])
					{
					 
						 while(h <j)
						 {
						     
						    ji[a[h]-'0'] = 0;
							h++; 
							
						 }
						 break;
					}
					
				}
				ji[a[j]-'0']++;
			}
			
		}
		for(int e = 1;e <= n;e++)
		{
			b[e]+=ji[e];
			ji[e] = 0;
			
		} 
		
		
	}
	for(int i = 1;i<= m;i++)
	{
		cout <<b[i]<< " ";
	}
	
	 
	
	
	return 0;
 } 
