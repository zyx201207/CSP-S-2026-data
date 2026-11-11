#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(l i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(l i=1;i<=n;i++){
		l cnt=1,t=m;
		for(l j=i-1;j>0&&t;j--){
			l x=a[i]-a[j];
			if(t>=x)t-=x,cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
