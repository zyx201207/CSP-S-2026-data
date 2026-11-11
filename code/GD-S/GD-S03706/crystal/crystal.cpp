#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long special=0;
bool str=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(i==2)
    	    special=a[i]-a[i-1];
    	else if(i>2&&special!=(a[i]-a[i-1]))
    		str=0;
	}
	sort(a+1,a+n+1);
	if(str==1)
	{
		int temp_sum=0,temp_ans=0;
		for(int i=0;;i+=special)
			if(temp_sum+i<=m)
			{
				temp_sum+=i;
				temp_ans++;
			}
			else
				break;
		cout<<temp_ans;
		return 0;
	}
    return 0;
}
