#include<bits/stdc++.h>
using namespace std;
int nn,anss;
long long jj=1,aa[200005],numm[200005];
char cc[200005],ss[200005];
int my_max(int a,int b,int c,int d,int e,int f)
{
	int kqx3=a;
	if (kqx3<b)
	{
		kqx3=b;
	}
	if (kqx3<c)
	{
		kqx3=c;
	}
	if (kqx3<d)
	{
		kqx3=d;
	}	
	if (kqx3<e)
	{
		kqx3=e;
	}
	if (kqx3<f)
	{
		kqx3=f;
	}
	return kqx3;
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>nn;
	for (int i=1;i<=nn;i++)
	{
		cin>>aa[i]>>cc[i]; 
		for (int gjj=1;gjj<=aa[i];gjj++,jj++)
		{
			ss[jj]=cc[i];
		}
		numm[i]=numm[i-1]+aa[i];
	}
	jj--;
	//c(xian pan duan)
	bool kqx=true;
	for (int i=1;i<=nn/2;i++)
	{
		if (ss[i]!=ss[jj+1-i])
		{
			kqx=false;
		}
	}
	if (kqx)
	{
		cout<<0;
		return 0;
	}
	while(true)
	{
		//find max's part
		long long maxx=-1,maxx_num;
		for (int i=1;i<=jj;i++)
		{
			if (maxx<aa[i])
			{
				maxx=aa[i];
				maxx_num=i;
			}
		}
		//look for the !same
		int x,y,xx,yy,r; 
		x=numm[maxx_num-1]+1;
		xx=jj+1-(numm[maxx_num-1]+1);
		y=numm[maxx_num];
		yy=jj+1-(numm[maxx_num]);
		r=my_max(abs(x-xx),abs(x-yy),abs(x-y),abs(y-xx),abs(y-yy),abs(xx-yy));
		for (int l=numm[maxx_num-1]+1;l<=numm[maxx_num];l++)
		{
			if (ss[l]!=ss[jj+1-l])
			{
				anss++;
			}
		}
		cout<<r<<" ";
		//aa[],ss[],numm[],jj turn small
		for (int i=jj-r;i<=jj;i++)
		{
			aa[i]=aa[i+r];
			ss[i]=ss[i+r];
			numm[i]=numm[i+r];
		}
		jj-=r;
		if (jj==0)
		{
			cout<<anss;
			break;
		}
	}
	//remember to delete "//"of"//freopen(----)"
	return 0;
}
