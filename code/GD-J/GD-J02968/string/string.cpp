#include<bits/stdc++.h>
using namespace std;
struct w
{
	long long x;
	char y;
}a[200005];
long long n,sum,k,tp1,tp2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i].x;
		cin>>a[i].y;
	}
	k=n-1;
	tp1=a[0].x;
	tp2=a[k].x;
	for(int i=0;i!=k;)
	{
		if(a[i].y!=a[k].y) sum+=(min(tp1,tp2));
		if(tp1>tp2)
		{
			tp1-=tp2;
			--k;
			tp2=a[k].x;
		}
		else if(tp2>tp1)
		{
			tp2-=tp1;
			++i;
			tp1=a[i].x;
		}
		else
		{
			++i;
			--k;
			tp1=a[i].x;
			tp2=a[k].x;
		}
	}
	cout<<sum;
	return 0;
}
