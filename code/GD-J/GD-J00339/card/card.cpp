#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],zz=0,c[500001];
bool p[300001],f[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		while(b[1]!=0) {b[zz]=0;zz--;}
		for(int j=1;j<=m;j++) p[j]=false;
		for(int j=1;j<=m;j++) f[j]=false;
		for(int j=i;j<=n;j++)
		{
			if(!f[a[j]]) {zz++;b[zz]=a[j];f[a[j]]=true;}
			else
			{
				while(b[1]!=0)
				{
					if(b[zz]==a[j]) break;
					else {f[b[zz]]=false;b[zz]=0;zz--;}
				}
			}
		}
		while(b[1]!=0){if(!p[b[zz]]){c[b[zz]]++;b[zz]=0;p[b[zz]]=true;zz--;}else{zz--;b[zz]=0;}}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
