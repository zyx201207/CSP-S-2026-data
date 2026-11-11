#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,mid,cnt=1,h=1;
bool cmp(long long x,long long y){
	return abs(x-mid)<abs(y-mid);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		mid+=(a[i]-a[i-1])*h;
		h++;
		while(mid>m){
			mid-=(a[i]-a[cnt]);
			cnt++;
			h--;
		}
		ans=max(ans,h);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
