//GZ-J00489 遵义市第四初级中学 游四鑫
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		sum=max(sum,(a[i]&a[i-1]));
	}
	cout<<sum;
	return 0;
} 
