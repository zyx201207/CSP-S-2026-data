#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500015],b[300015]={0},ss=0;
string k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++,ss=0)
	{
	memset(b,0,sizeof(b));
	k="";
	for(int i=j;i<=n;i++)
	{
		if(!b[a[i]]) k+=(a[i]+'0');
		else{
			for(int l=0;l<k.size();l++)
			{
				if(k[l]==(a[i]+'0'))
				{
				k.erase(l+1,k.size());	
				break;
				}
			}
		}
	}
	for(int i=0;i<k.size();i++)
	{
		if(k[i]==(j+'0')) ss++;
	}	
	cout<<ss<<" ";
	}
	
	return 0;
}
