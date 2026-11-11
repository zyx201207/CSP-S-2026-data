#include<bits/stdc++.h>
using namespace std;
long long a[10005],d=100000005,sum,bum;
int n;
char x;
string s,m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int c;
    	cin>>c>>x;
    	for(int i=1;i<=c;i++) s+=x;
    	sum+=c;
	}
	int y=s.length();
	for(int i=0;i<y;i++)
	{
	    a[s[i]]++; 
	}
	for(int i=0;i<y;i++)
	{
		d=min(a[s[i]],d);
		bum=max(a[s[i]],bum);
	}
		if(d==sum) {
		cout<<"0";
	    return 0;
    }
	if(bum>=sum-bum)
	{
	cout<<sum-bum;
    }
	else {
	cout<<d;
    }

	return 0;
} 
