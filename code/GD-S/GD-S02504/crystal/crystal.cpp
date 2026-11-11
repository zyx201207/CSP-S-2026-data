#include<bits/stdc++.h>
using namespace std;
#define in long long
const int N=5e5+5;
int n,m,a[N],l=1,ans,tmp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2;i<=n;i++){
		tmp+=(i-l)*(a[i]-a[i-1]);
		while(l<i&&tmp>m){
			l++;
			tmp=tmp-(a[i]-a[l]);
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
