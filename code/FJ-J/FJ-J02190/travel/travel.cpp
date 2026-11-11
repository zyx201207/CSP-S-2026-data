#include<bits/stdc++.h>
using namespace std;
int a,b,ans[5];
int wl[99][99];
char az[5],bz[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	wl['A']['B']=1;
	wl['B']['A']=1;
	wl['A']['C']=1;
	wl['C']['A']=1;
	wl['B']['C']=1;
	wl['C']['B']=1;
	wl['F']['D']=1;
	wl['D']['F']=1;
	cin>>a;
	cin>>az;
	cin>>b;
	cin>>bz;
	if(a==b)
	ans[1]=1;
	if(ans[1]==1&&az[0]==bz[0]&&az[1]==bz[1])
	ans[2]=1;
	if(ans[2]==1&&(wl[az[2]][bz[2]]==1))
	ans[3]=1;
	if(ans[3]==1&&abs(az[2]-bz[2])==1)
	ans[4]=1;
	for(int i=1;i<=4;i++)
	cout<<ans[i];
}