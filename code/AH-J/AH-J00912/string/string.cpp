#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r,sum[200005],i,j,t;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> a[i].s >> a[i].c;
		sum[i] = sum[i-1]+a[i].s;
	}
	l = 1;
	r = sum[n];
	i = 1;
	j = n;
	while(l<=sum[n]/2&&r>=sum[n]/2+1){
		t = min(sum[i]-l+1,r-sum[j-1]);
		if(a[i].c != a[j].c){
			ans += t;
		}
		l += t;
		r -= t;
		if(l>sum[i])i++;
		if(r<=sum[j-1])j--;
	}
	cout << ans;
	return 0;
}
