#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l[200005],r[200005],sum,lt,rt,ans;
char c[200005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		l[i]=sum+1,r[i]=sum+a[i];
		sum+=a[i];
	}
	for(int i=1,j=n;i<j;i++){
		while(i<j && sum-l[j]+1<=r[i]){
			if(c[j]!=c[i]){
				ans+=min(a[j],(sum-l[j]+1)-l[i]+1);
			}
			j--;
		}
		if(c[j]!=c[i]){
			ans+=min(r[i]-(sum-r[j]+1)+1,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
