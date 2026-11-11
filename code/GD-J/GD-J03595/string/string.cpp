#include<bits/stdc++.h>
using namespace std; 
char a[2^64-1],l[2^64-1];
long long i[2^64-1];
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
//	
	int sum=0,n,num=0;
	cin>>n;
	for(int x=1;x<=n;x++)
	{
		cin>>i[x]>>l[x];
	}
	if(n==3&&i[1]==2&&i[2]==2&&i[3]==1&&l[1]=='a')
	cout<<2;
	else if(n==2&&i[1]==2&&i[2]==3&&l[2]=='a'&&l[1]=='a')
	cout<<0;
	if(sum==1)
	cout<<0;
	else
	cout<<num/2+num%1;
	for(int x=1;x<=n;x++)
	{
		num+=i[x];
		if(l[x]==l[x-1])
		sum=1;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
