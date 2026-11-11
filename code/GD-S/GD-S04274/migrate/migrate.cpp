#include<bits/stdc++.h>
using namespace std;
int n,b,d,u,v,x[10005];
int main(){
	cin>>n>>b,d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]-x[j]<=d)
			{
				b+=d;
			}
		}
		
	}
	cout<<d;
}
