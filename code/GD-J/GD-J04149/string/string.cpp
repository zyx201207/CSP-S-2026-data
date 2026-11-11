#include<bits/stdc++.h> 
#define int unsigned long long 
const int N=2e5+21;
using namespace std;
struct node{
	int x;
	char y;
}a[N];
int sumn=0;
int nxtl=0,nxtr=0;
char nxtc;
signed main()
{
	cout<<nxtc;freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i].x>>a[i].y;
	int l=1,r=n;
	while(l<r)
	{
		if(nxtl!=0)
		{
			if(nxtc!=a[r].y)
			sumn+=nxtl;
			a[r].x-=nxtl;
		}
		else if(nxtr!=0) 
		{
			if(nxtc!=a[l].y)
			sumn+=nxtr;
			a[l].x-=nxtr;
			
		}
		nxtl=nxtr=0;nxtc=' ';
		if(a[l].x==a[r].x)
		{ if(a[l].y!=a[r].y){
				sumn+=a[l].x;
			}
			
		}
		else 
		{
			if(a[l].y==a[r].y)
			{nxtc=a[r].y;
				
				if(a[l].x>a[r].x){
				nxtl=a[l].x-a[r].x;
				nxtr=0;
				}
				else {
					nxtr=a[r].x-a[l].x;
					nxtl=0;
				}
			}
			else if(a[l].y!=a[r].y){
				sumn+=min(a[l].x,a[r].x);
				if(a[l].x>a[r].x){
					nxtl=a[l].x-a[r].x;
					nxtc=a[l].y;
				}
				else {
					nxtr=a[r].x-a[l].x;
					nxtc=a[r].y;
				}
			}
		}
		l++;
		r--;
	}
	int mid=ceil(1.0*n/2);
	if(n%2==1)
	{
		if(nxtc!=a[mid].y){
		sumn+=max(nxtl,nxtr);}
	}cout<<sumn;
	return 0;
} 
