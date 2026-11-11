#include<bits/stdc++.h>
using namespace std;
long long n,b[200005];
char a[200005];
unsigned long long sum;
int main()
{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			getchar();
			cin>>a[i];
		}
		for(int i=1,j=n;i<=ceil(n/2.0);i++,j--)
		{
			if(i!=1)
			{
				if(b[i]<=b[j])
				sum+=b[i]-(max(b[i-1],b[j+1])-min(b[i-1],b[j+1]));
			else if(b[j]<=b[i])
				sum+=b[j]-(max(b[i-1],b[j+1])-min(b[i-1],b[j+1]));
			}
			if(i==1)
			{
				if(a[i]==a[j])
				continue;
				else
				sum+=min(b[i],b[j]);
			}
		
	/*	if(a[i]!=a[j])
		sum+=max(b[i],b[j]);*/
		}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
	return 0;
} 
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
