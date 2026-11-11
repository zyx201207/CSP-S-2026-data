#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long cnt=0;
	int j=1;
	int ret=0;
	for(int i=1;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-j);
		while(j<=i&&cnt>m){
			cnt-=a[i]-a[j];
			j++;
		}
		ret=max(ret,(i-j+1));
	}
	cout<<ret;
	return 0;
}
