#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,cnt,l[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l[i]=l[i-1]+(a[i]-a[i-1])*(i-1);
		for(int j=1;j<i;j++){
			if(l[i]-l[j]<=m&&i-j+1>ans)ans=i-j+1;
			else break;
		}
	}
	cout<<ans;
	return 0;
}
