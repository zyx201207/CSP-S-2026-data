#include<bits/stdc++.h>
using namespace std;
//nobody should be undefined
const int N=2e5+5;
long long s;
int n,a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				s+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r])
		{
			if(c[l]!=c[r])
			{
				s+=a[r];
			}
			l++;
			r--;
			
		}
		else
		{
			if(c[l]!=c[r])
			{
				s+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		//cout<<s<<" "<<r<<" "<<a[r]<<" "<<l<<" "<<a[l]<<endl;
	}
	cout<<s;
	
}
//Trick||Treat!Trick||Treat!
