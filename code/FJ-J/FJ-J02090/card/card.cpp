#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[300005],c[500005],i,j,h;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;h=n;for(i=0;i<n;i++)cin>>c[i];
	while(n--){
		a[c[n]]++;j=h;while(j>n){
			j--;if(b[c[j]]>1){
			for(i=n;i<=j;i++)if(c[i]==c[j])break;j=i;
			}b[c[j]]++;
		}
	}
	for(i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}

