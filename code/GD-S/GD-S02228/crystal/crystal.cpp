#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long cnt=0,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	int xx=a[2]-a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
		cnt+=xx;
		}
		if(cnt>m)break;
		ans=i;
	}
	cout<<ans;
	return 0;
} 
