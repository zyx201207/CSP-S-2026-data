#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int x[100005];
		for(int i=1;i<=n;i++)cin>>x[i];
		int j[100005];
		for(int i=1;i<=n;i++)
			j[i]=x[i]-x[i-1];
		int now;
		for(int i=1;i<=n-1;i++)
		{
			if(j[i]>d)continue;
			else
			{
				if(j[i+1]>d)
			}
		}
	}
} 
