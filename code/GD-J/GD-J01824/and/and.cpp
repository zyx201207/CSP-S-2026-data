#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005];
string cmp(long long x)
{
	string q="",q2="";
	while(x)
	{
		q+=(x%2+'0');
		x/=2;
	}
	for(int i=q.size()-1;i>=0;i--) q2+=q[i];
	return q2;
}
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n,greater<long long>());
	long long ma=-1,l,r,f=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) f++;
		else 
		{
			if(f>ma) ma=f,r=i-1;l=i-ma;
			f=1;
		}
	}
	if(ma>=k) cout<<a[l];
	
	else 
	{
		if(k==2)
		{
			long long ma=-1;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					string o="";o+=cmp(a[i]);
					string p="";p+=cmp(a[j]);
					string h="";
					for(int q=0;q<min(o.size(),p.size());q++)
					{
						if(o[q]==p[q]) h+="1";
						else h+="0";
					}
					long long d=1,ans=0;;
					for(int q=0;q<=h.size();q++)
					{
						ans+=(h[q]-'0')*d;
						d*=2;
					}
					ma=max(ans,ma); 
				}
			}
			printf("%lld",ma);
		}
	}
	return 0;
} 
