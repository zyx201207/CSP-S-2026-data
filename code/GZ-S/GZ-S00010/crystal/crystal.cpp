//GZ-S00010 黎平县第二中学 唐启谦
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[500000],ans,res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(i!=n-1){
			ans--;
			m+=ans*(a[i+1]-a[i]);
		}else ans++;
		for(int j=i-ans;j>=0;j--){
			if(a[i]-a[j]<=m){
				m-=a[i]-a[j];
				ans++;
			}else break;
		}res=max(res,ans);
	}cout<<res;
	return 0;
}
