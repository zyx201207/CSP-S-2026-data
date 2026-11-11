#include<bits/stdc++.h>
using namespace std;
long long a[500001],num[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long num=0,p=m;
		for(int j=i;j>=1;j--){
			if(p>=a[i]-a[j]){
				num++;
				p-=a[i]-a[j];
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
