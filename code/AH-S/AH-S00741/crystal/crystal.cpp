#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500001],c,s,m,i,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(i=n;i>=2;i--){
		c=0;for(j=i-1;j>=1;j--){c=c+a[i]-a[j];if(c>m)break;}
		s=max(s,i-j);
	}cout<<s;
	return 0;
}
