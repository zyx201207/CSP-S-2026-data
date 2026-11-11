#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<long long>());
	long long gc=a[0]-a[1],f=0;
	for(long long i=1;i<n-1;i++)
		if(a[i]-a[i+1]!=gc){
			f=1;
			break;
		}
	if(f==1){
		for(long long i=0,sum=0;i<n;i++)
		{
			long long tt=0;
			for(long long j=i+1,t=m;j<n&&t>0;j++)
			{
				t-=a[i]-a[j];
				if(t>=0)
					tt++;
			}
			if(i!=0&&a[i]==a[i-1])
				sum++;
			else
				sum=0;
			ans=max(ans,tt+sum);
		}
		cout<<ans+1<<endl;
	}else{
		long long i;
		for(i=0;i*gc<m;i++){
			m-=i*gc;
		}
		cout<<i<<endl;
	}
	return 0;
}
