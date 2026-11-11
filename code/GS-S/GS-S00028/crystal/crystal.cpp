#include<bits/stdc++.h>
using namespace std;
bool emp(int a,int b)
{
	return a>b;
}


int main()
{
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
long long n,m;
long long a,ha;
int sj[n];
int xb[n];
for(int i=0;i<n;i++)
cin>>sj[i];

if(m==0)
{
	for(int i=0;i<n;i++)
	cout<<sj[i];	
}
for(int i=0;i<n;i++)
	a=a+sj[i];
ha=a/2;


 
 return 0;
 
} 
