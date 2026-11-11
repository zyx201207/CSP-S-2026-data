#include<bits/stdc++.h>
using namespace std;
long long n,zc=0,zj,q=0,h,sc=0;
long long len[1000000];
string zf;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>len[i];
		cin>>zf[i];
		zc+=len[i];
	}
	zj=zc/2;
	h=n-1;
	if(zc%2!=0)
	{
		for(int i=0;i<n;i++)
		{
			if((zc-len[i])<=zj)
			{
				len[i]-=1;
				break;
			}
			zc-=len[i];
		}
	}
	for (int i=0;i<zj;i++){
		if(len[q]==0){
			q++;
		}
		if(len[h]==0){
			h--;
		}
		if(zf[q]!=zf[h]){
			sc++;
		}
		len[q]--;
		len[h]--;
	}
	cout<<sc;
	return 0;
}
