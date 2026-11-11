#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e5+5;
int a[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int tmp=m,tmp2=0;
		for(int j=i;j>=1;j--){
			if(tmp>=a[i]-a[j]){
				tmp-=(a[i]-a[j]);
				tmp2++;
			}
			else break;
		}
		if(ans>=tmp2)break;
		else ans=tmp2;
	}
	cout<<ans;
	return 0;
}
