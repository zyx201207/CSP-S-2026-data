#include <bits/stdc++.h> 
using namespace std;

long long a[500005];
long long m,n;
long long o,t;
long long cnt=0;
int pd=1;
long long l;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==1) o=a[1]-a[0];
		if(i>1&&!(a[i]-a[i-1]==o)) pd=0;
	}
	
	if(pd==1)
	{
		t=1;
		while(1)
		{
			cnt=(1+t)*t*o/2;
			if(cnt>m) break;
			t++;
		}
		cout<<t;
	}
	else
	{
		t=0;
		sort(a,a+n);
		while(cnt<=m)
		{
			t++;
			l=a[t]-a[t-1];
			cnt+=l*t;
		}
		cout<<t;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
