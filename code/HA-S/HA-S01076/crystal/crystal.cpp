#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,a,b,c,d;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		a>0;b>0;c>0;
		if(a<b<c)
		{
			a=a+(c-a);
		}
		if(a<b<c)
		{
			b=b+(c-b);
		}
		m=(c-a)+(c-b);
		d=a+b+c;
	}
	cout<<d;
	return 0;
} 
