#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,mid;
bool cmp(long long x,long long y){
	return (x-mid)<(y-mid);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	mid=a[(1+n)/2];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long x=abs(a[i]-mid);
		if(m>=x){
			ans++;
			m-=x;
		}
	}
	cout<<ans;
	return 0;
}
