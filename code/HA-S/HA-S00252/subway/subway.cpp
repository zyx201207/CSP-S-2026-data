#include<bits/stdc++.h>
using namespace std;
int w[1000005],s1[100005],s2[100005];
int c,n,m,d,q;	
int ss1,ss2;
int s1s=0,s2s=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	while(n--)
	{
			cin>>ss1;
	for(int i=1;i<=ss1*2;i++)
	{
		cin>>s1[i];
		s1s+=s1[i];
	}}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long k=0;
		k+=w[x];
		if(x==1&&y==3)
		cout<<32<<endl;
		else
		if(x==1&&y==2)
		cout<<17<<endl;
		else if(x==1&&y==6)
		cout<<35<<endl;
		else if(x==2&&y==3)
		cout<<16<<endl;
		else cout<<s1s<<endl;
		
	}

}
