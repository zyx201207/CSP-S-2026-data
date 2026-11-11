#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long a[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int w=1;w<=t;++w){
		long long n,d;
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i] ;
		}
		for(int i=1;i<n;++i){
			long long num=2*d-1;
			for(int j=i+2;j<=n;++j){
				if(a[j]-a[i]==num&&j>i+1) ++ans;
				else if(a[j]-a[i]>=num) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
