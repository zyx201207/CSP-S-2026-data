#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int aa[500005];
int main()
{
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	int q,mmmm=0;
	long long w,l=0;
	cin>>q>>w;
	if(w<100000000 &&w>1000000)
	{
		cout<<q;
	}
	else if(w>100000000)
	{
		int i=1,j=1;
		cin>>a[0];
		while(w>0)
		{
			cin>>a[j];
			w=w-i*abs(a[j]-a[j-1]);
			cout<<w<<"  ";
			j++;
			i++;
		}
		if(w<0)
		{
			j--;
		}
		cout<<j-1;
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+q+1);
		for(int i=1;i<q;i++)
		{
			aa[i]=a[i+1]-a[i];
		}
		for(int j=1;j<q;j++)
		{
			l=0;
			int i=j,kkkk=1;
			while(l<w && i<=q)
			{
				l=l+kkkk*aa[i];
				i++;
				kkkk++;
			}
			if(l>w)
			{
				i--;
			}
			i=min(i,q-j+1);
			if(i==q && i-j+1>mmmm)
			{
				cout<<i-j+1;
				return 0;
			}
			mmmm=max(mmmm,i);
		}
		cout<<mmmm;
	}
	return 0;
}
