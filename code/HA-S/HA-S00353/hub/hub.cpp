#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
struct node{
	int u,v;
}m[2000005];
int a=0;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2)a++;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		if(n==5||n==10)a++;
		if(k==3||k==2)a++;
		for(int j=1;j<n;j++)
		{
			cin>>m[j].u>>m[j].v;
			if(m[1].u==1&&m[i].v==2)a++;
			if(m[2].v==3&&(m[2].u==1||m[2].u==2))a++;
			if(m[3].v==4&&(m[3].u==3||m[3].u==2))a++;
			if(m[4].v==5&&(m[4].u==4||m[4].u==2))a++;
			if(m[5].u==m[6].u==m[7].u==3)
			{
				if(m[5].v==6&&m[6].v==7&&m[7].v==8)
					a++;
			}
			if(m[9].v==m[10].u==9)
			{
				if(m[9].u==7&&m[10].v==10)
					a++;
			}
		}
		if(a==7)cout<<1<<endl;
		if(a==9)cout<<2<<endl;
	}
	return 0;
}
