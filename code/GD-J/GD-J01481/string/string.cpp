#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
const int M = 1e9+10;
long long n,len,cnt,x;
long long a[N];
string c[N],b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=1,f=1,j=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		x+=a[i];
		if(i>=2){
			if(a[i]==a[i-1]){
			}else{
			flag=0;
			}
		}
		if(i>=2){
			if(c[i]==c[i-1]){ f=1;
			}else{
			j=0;
			}
		}
	}
	if(f)
	{
		if(j!=0)
		{
			cout<<0;
			return 0;
		}
	}
	if(flag)
	{
		//cout<<1000000000000<<endl;
		len=n/2;
		for(int i=1,j=n;i<=len;i++,j--)
		{
			if(c[i]!=c[j]) cnt++;
		}
		cout<<cnt;
	}else{
		//cout<<555555555555<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				b[j]=c[i];
			}
		}
		len=x/2;
		for(int i=1,j=x;i<=len;i++,j--)
		{
			if(b[i]!=b[j]) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
