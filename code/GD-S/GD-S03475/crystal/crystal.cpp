#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=1;
int a[500100],b[500100],c[500100];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
	{
		int k=0;
		int p=i;
		int sum=1;
		int q=m;
		while(q>=0)
		{
			if(k+b[p]<=q)
			{
				k+=b[p];
				sum++;
				if(sum>ans)
				{
					ans=sum;
				}
				q-=k;
				p--;
			}
			else break;
			if(p==1)
			break;
		}
	}
	cout<<ans<<endl;
} 
