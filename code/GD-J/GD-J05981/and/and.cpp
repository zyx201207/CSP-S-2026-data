#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string z[N];
int change(int a1)
{
	int a2,k[N],o=0,s=0;
	while(a1!=0)
	{
		k[o]=a1%2;
		a1=a1/2;
		o++;
	}
	for(int i=0;i<=o;i++)
	{
		s=s+k[i]*pow(10,i);
	}
	return s;
}
int yunsuan(string a1,string a2)
{
	int z[N],n=0,k=0;
	for(int i=0;i<a1.size();i++)
	{
		if(a1[i]=='1')
		{
			a1[i]='1';
		}
		else
		{
			a1[i]='0';
		}
	}
	for(int i=0;i<a2.size();i++)
	{
		if(a2[i]=='1')
		{
			a2[i]='1';
		}
		else
		{
			a2[i]='0';
		}
	}
	if(a2.size()>a1.size())
	{
		k=a2.size();
	}
	else{
		k=a1.size();
	}
	for(int i=0;i<k;i++)
	{
		if(a1[i]==a2[i])
		{
			z[i]='1';
		}
		else{
			z[i]='0';
		}
	}
	for(int i=0;i<k;i++)
	{
		n=n+pow(2,i)*z[i]; 
		}	
		return n;
}
int main(){
	string n,l;
	string a[N];
	cin>>n>>l;
	//for(int i=0;i<n;i++)
	//{
		//cin>>a[i];
		
	//}
	cout<<yunsuan(n,l);
	return 0;
}
