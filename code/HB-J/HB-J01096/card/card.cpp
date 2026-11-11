#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
struct iyn{
	bool f;//wether discover
	int p=0;// first place 
	int t;// last times
}times[300005];
int n,m,c=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		c=1;
		for(int j=i;j<=n;j++)
		{
			b[c]=a[j];
			int x=b[c];//x:now_number
			times[x].f=true; //discover times add
			if(times[x].p!=0)// second discover
			{
				for(int O=times[x].p;O<c;O++)
					times[O].f=false; // POP
				c=times[x].p;
				b[c]=x;//re place
				times[b[c]].f=true;
			}
			times[b[c]].p=c;//re first dicover place
			c++;
		}
		for(int j=1;j<=m;j++){
			if(times[j].f==true)
			{
				times[j].t++;		
			}
			times[j].f=false;
			times[j].p=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<times[i].t<<" ";
}
