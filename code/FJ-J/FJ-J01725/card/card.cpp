#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300000];
int a1,a2;
bool v[3];
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		v[1]=0,v[2]=0;
		for(int j=i;j<=n;j++)
			for(int l=j;l<=n;l++)
				if(a[j]==a[l]){
					for(int k=j;k<l;k++)
						v[a[k]]=1;
				}
		if(v[1]==0)x++;
		if(v[2]==0) y++;
	}
	cout<<x<<" "<<y;
	return 0;
 } 
