#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
long long m,d,a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			if(d>=a[i]-a[j]){
				d-=(a[i]-a[j]);
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
