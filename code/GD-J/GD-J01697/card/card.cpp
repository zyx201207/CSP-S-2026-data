#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N];
struct node{
	int nxt;
	int a;
} tab[N];
int tim=1;
bool bz[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tab[i].nxt=i+1;
		tab[i].a=a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		memset(bz,0,sizeof(bz));
		for(int j=tim;j<=n;j++)
		{
			if(bz[tab[j].a]==0)
			{
				bz[tab[j].a]=j;
			}
			else
			{
				int l=bz[tab[j].a],r=j;
				cout<<l<<" "<<r<<" "<<tab[j].a<<endl;
				tab[l-1].nxt=r+1;
			}
		}
		for(int i=1;i;i=tab[i].nxt)
		cout<<tab[i].a<<" ";
		cout<<endl;
	}
	return 0;
}
