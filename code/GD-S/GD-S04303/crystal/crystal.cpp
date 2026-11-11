#include<bits/stdc++.h>
using namespace std;
int a[500090];
int b[500090];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long sum=0;
	long long s;
	long long shus=0;
	long long shusum=0,k=0;
	for(int i=1;i<=n;i++)
	{
		for(int f=1;f<i;f++)
		{
			b[f]=a[i]-a[f];
			s=0;
			shus=0;
			k=i;
			for(int p=1;p<=i;p++)
			{
				
				for(int j=1;j<k;j++)
				{
					if(b[j]<b[j+1])
					{
						swap(b[j],b[j+1]);
					}
				}
				if(s+b[k]>m)
				{
					break;
				}
				else if(s+b[k]==m){
					shus++;
					s=s+b[k];
					break;
				}
				else{
					shus++;
					s=s+b[k];
					k--;
				}
			}
			if(shus>shusum)
			{
				shusum=shus;
			}
		}
	}
	cout<<shusum;
	return 0;
} 
