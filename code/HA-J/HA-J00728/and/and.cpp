#include<bits/stdc++.h>
using namespace std;
long long a,b,c[999999],max1=0,x,y,bes=0,p,z,l[999999],u=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
	cin>>c[i];bes=max(bes,c[i]);}
	if(b==1){cout<<bes;return 0;}
	for(int i=1;i<a;i++)
		for(int j=i+1;j<=a;j++)
	{p=c[i]&c[j];
		if(p>max1){max1=c[i]&c[j];x=i;y=j;
		}
	}
	c[x]=0;c[y]=0;b-=2;
	if(b==0){cout<<max1;return 0;}
	u=max1;
	while(b){
	for(int i=1;i<=a;i++)
		l[i]=u&c[i];
		u=0;
	for(int i=1;i<=a;i++)
	if(l[i]>u){z=i;u=l[i];}
	b--;l[z]=0;}
	cout<<u;
	return 0;
 } 
