#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m; 
string b,d;
int main(){
	freopen(and,r,stdin);
	freopen(and,w,stdout);
	cin>>n,m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	 for(int i =1;i<=n;i++)
	 {
	 	for(int j = i+1;j<=n;j++)
	 	{
	 		int c=a[i];
	 		int r=a[j];
	 		while(c)
	 		{
	 			b+=c%2;
	 			c/2;
			 }
			
		 }
	 }
	 cout<<0;
	return 0;
} 
