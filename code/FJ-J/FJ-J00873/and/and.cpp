#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[10000][20000];
bool d[40000][20000];
int x,ans[40000],s=0;
bool shu(int i)
{	bool c;
	if(i==1) return 1;
	else 
	{c=0;return c;
	}
}
void zer(int w,int i)
{
	bool b[10000];
	int d,j=0;
	do
	{	
		d=w%2;
		b[j]=shu(d);
		w/=2;
		j++;
	}while(w!=0);
	for(int q=j;q>=0;q--)
	{
		a[i][j-q]=b[q];

	}
}
void yu(bool q,bool w,int i,int j)
{
	if(q==w)
	d[i][j]+=1;
	else d[i][j]+=0;
}

int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		zer(x,i);
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<sizeof(a[i]);j++)
	{
		cout<<a[i][j];
	}
	}*/
	for(int ii=0;ii<n;ii++)
	{for(int i=0;i<sizeof(a[ii])-1;i++)
	{
		
			yu(a[ii][i],a[ii][i+1],ii,i);
			

	}
	
	
	}
	for(int i=0;i<sizeof(d);i++)
	{
		for(int j=0;j<sizeof(d[i]);j++)
		{
		int z;
		if(d[i][sizeof(d[i])-j]==1) z=1; 
		else z=0;
		ans[i]+=z*pow(2,j);
		}
		s=max(ans[i],s);
	}
	cout<<s;
return 0;
} 
