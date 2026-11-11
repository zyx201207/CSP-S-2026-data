#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N],ans,sum[N],lst[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin>>n;
	ll l=1,r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
		sum[i]=r;
	}
	int i=1,j=n;
	while(i<j){
		ll mov=min(sum[i]-l+1,r-sum[j-1]);
		if(c[i]!=c[j])ans+=mov;
		l+=mov;
		r-=mov;
		if(l>sum[i])i++;
		if(r<=sum[j-1])j--;
	}
	cout<<ans;
	return 0;
}
