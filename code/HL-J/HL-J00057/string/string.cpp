#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+10;
struct qwq{
	long long l;
	char c;
}a[N];
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	
	long long n;
	cin>>n;
	//cout<<1<<endl;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i].l>>a[i].c;
	}
	//cout<<1<<endl;
//	int jo;
//	if(n%2==0) jo=1;
//	else jo=2;
	long long le=1,ri=n;
	long long cnt=0;
	while(le+1<ri)
	{
		long long dl=a[le].l,dr=a[ri].l;
		if((a[le].c==a[ri].c))
		{
			int m=dl-dr;
			if(m<0)
			{
				le++;
				a[ri].l=dr-dl;
			}
			else if(m>0)
			{
				ri--;
				a[le].l=dl-dr;
			}
			else if(m==0)
			{
				le++;
				ri--;
			}
			//cout<<le<<' '<<ri<<endl;
		}
		
		if(a[le].c!=a[ri].c)
		{
			if(a[ri].l<=a[le].l)
			{
				a[ri].c=a[le].c;
				cnt+=a[ri].l;
				//cout<<a[ri].c<<endl;
			}
			else
			{
				a[le].c=a[ri].c;
				cnt+=a[le].l;
				//cout<<a[le].c<<endl;
			}
			//cout<<cnt<<endl;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}