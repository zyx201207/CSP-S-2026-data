#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		int m1=m,sum=1;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				m1-=a[i]-a[j];
				sum++;
			}
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
