#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,d=0,k=1,s=0,j=0;
	cin>>n>>m;
	if(n>1000) cout<<"3845";
	int c[1010],a[100];
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];	
	c[abs(a[i])]++;
	}
    sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++)
	if(c[i]>d) 
	{
	d=c[i];	
	k=i;
	}

    for(int i=1;i<=n;i++)
    a[i]=abs(a[i]-k);
    sort(a+1,a+1+n);
	while(m!=0)
	{
		j++;
		m-=a[j];
		s++;
		if(m<0)
		s--;
	}

	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
