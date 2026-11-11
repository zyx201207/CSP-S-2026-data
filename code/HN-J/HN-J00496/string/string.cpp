#include<iostream>
using namespace std;
string str;
int n;
char c[200005];
int a[200005];
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int sl=a[1];
	int sr=a[n];
	for(int l=1,r=n;;)
	{
		if(sl==0)
		{
			sl=a[++l];
		}
		if(sr==0)
		{
			sr=a[--r];
		}
		int minn=min(sl,sr);
		sl-=minn;
		sr-=minn;
		//cout<<"l:"<<l<<"  r:"<<r<<" sl:"<<sl<<" "<<" sr:"<<sr<<" minn:"<<minn<<"\n";
		if(c[l]!=c[r])
		{
			sum+=minn;
		}
		if((l==r||l+1==r)&&(sl==0||sr==0))
		{
			cout<<sum;
			break;
		}		
	}
	return 0;
}
