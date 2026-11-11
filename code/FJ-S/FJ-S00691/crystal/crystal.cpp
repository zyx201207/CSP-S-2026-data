#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
unsigned long long f[N];
bool check(int x){
	for(int i=x;i<=n;i++)
		if(f[i]-f[i-x]-(i-x)*(a[i]-a[i-x])<=m)
			return true;
	return false;
}
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	int lt=2,rt=n,ans=1;
	while(lt<=rt){
		int mid=(rt-lt)/2+lt;
		if(check(mid)){
			ans=mid;
			lt=mid+1;
		}else
			rt=mid-1;
	}
	cout<<ans;
	return 0;
}
