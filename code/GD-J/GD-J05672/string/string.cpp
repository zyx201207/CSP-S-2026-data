#include<bits/stdc++.h>
using namespace std;
int n,size,num=0;
long long a[200005];
char c[200005];
void binery(int l,int r)
{
	for(int i=1; i<=size/2; i++)
	{
		if(c[l]==c[r])
		{
			l-=1;
			r+=1;
		}
		else
		{
			num++;
		}
			
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int order=1;
	for(int i=1; i<=n; i++)
	{
		char cc;
		cin>>a[i]>>cc;
		for(int j=order; j<order+a[i]; j++) c[j]=cc;
		size+=a[i];
		order+=a[i];
	}
	if(size%2==0)
	{
		int le=size/2;
		int ri=size/2+1;
		binery(le,ri);
	}
	if(size%2==1)
	{
		int lee=size/2;
		int rii=size/2+2;
		binery(lee,rii);
	}
	cout<<num;
	return 0;
}
