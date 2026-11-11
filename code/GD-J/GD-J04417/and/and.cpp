#include<bits/stdc++.h>
int a[200010];
using namespace std;
int b[100000010],ab=1,num=0,as=0;
bool an(int x,int y)
{
	while(x){
		if(x%2==y%2)
		{
			b[ab]=x%2;
			num=x%2;
			for(int i=0;i<ab;i++){
				num*=2;
			}
			as+=num;
		}
		else{
			b[ab]=0;
		}
		x/=2;
		y/=2;
		ab++;
	}
}
int main()
{
	int n,m,maxn=0,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
		{
			an(i,j);
			if(as>maxn){
				x=i,y=j;
				maxn=as;
			}
		}
	}
	a[x]=0;
	a[y]=0;
	for(int i=1;i<=m-2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sc=maxn;
			an(maxn,a[1]);
			if(an(sc,a[j])>as){
				maxn=an(sc,a[j]);
			}
		}
	}
	cout<<maxn;
}
