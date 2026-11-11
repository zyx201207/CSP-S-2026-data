#include<bits/stdc++.h>
using namespace std;
int cnt,o,r[1000],q, n,sum[100000];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
		cin>>q;
		for(int j=0;j<r[i];j++)
			sum[j]=q;
	}
	for(int t=0;t<n;t++)
	{
		cnt+=r[t];
	}
	cnt=cnt/2;
	for(int y=n;y>n-cnt;y--)
	{
		for(int e=0;e<cnt;e++)
		{
			if(y==e)
			return 0;
			if(sum[y]==sum[e])
			{
				o++;
			}
		}
	}
	cout<<(o)/2;
	return 0;
}
