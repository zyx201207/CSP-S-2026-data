//GZ-J00585 李博煜 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	cnt=n;
	for(int i=1;i<=m;i++){
		ans=ans&a[cnt];
		cnt--;
	}
	cout<<ans;
	return 0;
}
