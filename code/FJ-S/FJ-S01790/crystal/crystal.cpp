#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500001],maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=3,j=a[2]-a[1];i<=n;i++) if(a[i]-a[i-1]!=j){
		maxx=0;
		break;
	}
	if(maxx){
		for(maxx=0;;maxx++) if((1+maxx)*maxx/2*(a[2]-a[1])>m) break;
		cout<<maxx;
		return 0;
	}
	for(long long i=1,x=1,all=m;i<=n;i++,x=1,all=m){
		for(long long j=i-1;j>=1;j--){
			if(all>=a[i]-a[j]) all-=(a[i]-a[j]),x++;
			else break;
		}
		maxx=max(maxx,x);
	}
	cout<<maxx;
	return 0;
}
