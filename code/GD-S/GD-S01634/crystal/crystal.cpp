#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ji=1,x=0;
	for(long long i=2;i<=n;i++){
		if((a[i]-a[i-1])*ji+x>m){
			ans=max(ans,ji);
			x+=(a[i]-a[i-1])*ji;
			while(ji>0&&x>m){
				x-=a[i]-a[i-ji];
				ji--;
			}
			ji++;
		}
		else{
			x+=(a[i]-a[i-1])*ji;
			ji++;
		}
	}
	ans=max(ans,ji);
	cout<<ans;
}
