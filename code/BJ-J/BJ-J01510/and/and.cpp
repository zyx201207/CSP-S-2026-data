#include<bits/stdc++.h>
using namespace std;
int c[1000001],j4[1000001],j2[10000001],j3[1000001];
long long ans=1,sum=0,cnt=0;
int main()
{
	freopen('and.in','r',stdin);
    freopen('and.out','w',stdout);
    long long a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=a;i++)
    {
		for(int h=i+1;h<=a;h++)
		{
			int m=0,l;
			l=c[i];
			while(l!=0)
			{
				m++;
				j4[m]=l%2;
				l/=2;
			}
			int n=0,r;
			r=c[h];
			while(r!=0)
			{
				n++;
				j2[n]=r%2;
				r/=2;
			}
			for(int j=1;j<=max(m,n);j++)
			{
				if(j4[j]!=j2[j])
				{
					j3[j]=0;
				}
				else if(j4[j]==j2[j]&&j4[j]==0){
					j3[j]=0;
				}
				else
				{
					j3[j]=1;
				}
			}
			for(int j=1;j<=max(m,n);j++)
			{
				if(j3[j]==1)
				{
					for(int k=1;k<=j-1;k++)
					{
						ans*=2;
					}
					sum+=ans;
					ans=1;
				}

			}
			cnt=max(cnt,sum);
			sum=0;
			ans=1;
			for(int j=1;j<=max(m,n);j++)
			{
				j2[i]=j3[i]=j4[i]=0;
			}
		}
    }
    cout<<cnt;
    return 0;
}



