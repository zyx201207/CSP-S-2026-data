#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int a2,ans;
	for (int i=1;i<=n;i++){
		int m2=m;
		a2=1;
		for (int j=i-1;j>=1;j--){
			if (m2>=a[i]-a[j]){
				m2=m2-a[i]+a[j];
				a2++;
			}
			ans=max(ans,a2);
			if (m2<=0){
				a2=1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
