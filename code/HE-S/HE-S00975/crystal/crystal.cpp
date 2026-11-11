#include<bits/stdc++.h>
using namespace std;
long long a[100000001];
int czcs[100000001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;m>0;i++)
	{
		if(a[i]<=a[i+1])
		{
			if(m>=a[i+1]-a[i]){
				m-=a[i+1]-a[i];
				a[i]=a[i+1];
				if(a[i-1]<a[i])
				{
					i==1;
				}
			}
			
		}
	}
	cout<<m<<endl;
	int ccsz=0;//用来存储和 
	int cum=1;//次数 
	for(int i=n;i>=1;i--)
	{
		if(a[i]==a[i-1])
		{
			ccsz+=a[i];
			cum+=1;
		}else{
			if(a[i]==a[i+1])
			{
				ccsz+=a[i];
				cum+=1;
				break;
			}
		}
		
	}
	cout<<cum<<'\n';
 } 
