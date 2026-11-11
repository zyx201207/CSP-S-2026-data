#include<bits/stdc++.h>
using namespace std;
long long m,n,a[6000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=100100;
	}
	sort(a+1,a+n+1);
	int ans=0;
	long long now=0,aa=1;
	for(int i=1;i<=n;i++){
		now=0,aa=1;
		for(int j=i-1;j>=1;j--){
			now+=(a[i]-a[j]);
			if(now<=m){
				aa++;
			}
			else{
				break;
			}
		}
		if(aa>=ans){
			ans=aa;
			}
	}
	cout<<ans;
	return 0;
}

