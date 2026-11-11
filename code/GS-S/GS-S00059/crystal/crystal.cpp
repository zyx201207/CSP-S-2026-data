#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long long a[500005];

bool cmp(long long x,long long y)
{
	return x<y;
}

int main()
{
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m;
	cin>>n>>m;
	
	bool f1=1,f2=1;
	long long k=0;
	
	cin>>a[1]>>a[2];
	k=a[2]-a[1];
	if(a[1]!=1||a[2]!=2)
		f1=0;
	for(long long i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)
			f1=0;
		if(a[i]-a[i-1]!=k)
			f2=0;	
	}
	
	if(m==0){
		cout<<1;
		return 0;
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	
	if(f1==1||k==1){
		for(long long i=2;i*(i-1)/2<=m;i++){
			if(i*(i-1)/2>m){
				cout<<(i-1);
				return 0;
			}
			if(i==n){
				cout<<n;
				return 0;
			}
		}
	}
	
	if(f2==1){
		for(long long i=2;i*(i-1)/2*k<=m;i++){
			if(k*i*(i-1)/2>m){
				cout<<(i-1);
				return 0;
			}
			if(i==n){
				cout<<n;
				return 0;
			}
		}
	}
	
	sort(a+1,a+n+1,cmp);
	
	long long mx=0;
	
	for(long long w=1;w<n;w++)
	{
		long long m1=0;
		for(long long i=w+1;i<=n;i++){
			if(a[i]==a[i-1])
				continue;
			m1+=(a[i]-a[i-1])*(i-w);
			if(m1>m){
				long long x=i-w;
				for(long long l=w-1;l>0;l--)
				{
					m1+=(a[i-1]-a[l]);
					x++;
					if(m1>m)
					{
						x--;
						mx=max(mx,x);
						break;
					}
				}
				mx=max(mx,x);
				break;
			}	
		}
		if(mx>=n-w+1)	
			break;
	}
	/*for(int i=n;i>1;i--)
	{
		long long m1=0;
		for(int j=i-1;j>=1;j--)
		{
			m1+=(a[i]-a[j]);
			if(m1>m)
			{
				mx=max(mx,i-j+1);
				break;
			}
		}
		if(m1<=m)
		{
			mx=max(mx,i-1);
			break;
		}
			
	}*/
	if(mx==0)
		cout<<n;
	else
		cout<<mx;
	return 0;
}
