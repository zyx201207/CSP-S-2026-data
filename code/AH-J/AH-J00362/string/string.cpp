#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n;
long long a[N];
char c[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	long long j=1;
	int s=1,t=n;
	long long ans=0;
	while(s<t)
	{
		if(c[s]==c[t])
		{
			if(a[s]<a[t])
			{
				j+=a[s];
				k-=a[s];
				a[t]-=a[s];
				s++;
			}
			else
			{
				j+=a[t];
				k+=a[t];
				a[s]-=a[t];
				t--;
			}
		}
		else{
			if(a[s]<a[t])
			{
				j+=a[s];
				k-=a[s];
				a[t]-=a[s];
				ans+=a[s];
				s++;
			}
			else
			{
				j+=a[t];
				k+=a[t];
				a[s]-=a[t];
				ans+=a[t];
				t--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
