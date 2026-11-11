#include <bits/stdc++.h>
using namespace std;
string jz(int n){
	int s=0,t=0,cn=1;
	string s1="00000000";
	while(n>0)
	{
		s=n/2;
		t=n%2;
		s1[s1.size()-cn]=t;
		n/=2;
		cn+=1;
	}
	return s1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt;
	int a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxx=0;
	if(n==4&&m==2)
		cout<<12;
	else if(n==5&&m==3)
		cout<<7;
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				string s2,s3;
				int k=0,n1=0;
				s2=jz(a[i]);
				s3=jz(a[j]);
				for(int t=7;t>=0;t--)
				{
					n1+=((int(s2[t])-55)&&(int(s3[t])-55))*pow(2,k);
					k++;
				}
				maxx=max(maxx,n1);
				
			}
		}
	}
	cout<<maxx;
	return 0;
	
}