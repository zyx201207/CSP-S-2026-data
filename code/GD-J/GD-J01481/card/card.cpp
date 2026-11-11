#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
const int M = 3*1e5+10;
long long n,m,ans,d,s;
long long a[N],b[N],c[M];
bool flag=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<"¾Ö"<<i<<endl;
		for(int j=i;j<=n;j++)
		{
			for(int z=1;z<=d;z++)
			{
				if(a[j]==b[z]){
					flag=0;
					s=z;
				}
				if(flag==0)
				{
					b[z]=0;
				}
			} 
			if(flag==0)
			{
				d=s;
				b[d]=a[j];
			}else{
				b[++d]=a[j];
			}
			flag=1;
			//cout<<"b[d]="<<b[d]<<endl;
		//	for(int g=1;g<=d;g++)
		//	{
		//	cout<<" "<<b[g];
		//	}cout<<endl;
		}
		for(int j=1;j<=d;j++)
		{
			if(b[j]!=0)
			{
				c[b[j]]++;
			}
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
