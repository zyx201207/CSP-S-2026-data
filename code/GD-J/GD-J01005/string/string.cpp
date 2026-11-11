#include<bits/stdc++.h>
#define int long long
using namespace std;
int oo, kk, n, a[200005], ans=0;
char c[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++)cin>>a[i]>>c[i];
	int i=1, j=n;
	oo=a[1], kk=a[n];
	while(i<j){
		if(i==j)break;
		if(oo>kk){
			oo-=kk;
			if(c[i]!=c[j]){
				ans+=kk;
			}
			j--;
			kk=a[j];
		}
		else if(oo<kk){
			kk-=oo;
			if(c[i]!=c[j])ans+=oo;
			i++;
			oo=a[i];
		}
		else{
			if(c[i]!=c[j])ans+=oo;
			i++, j--;
			oo=a[i], kk=a[j];
		}
	}
	cout<<ans;
	return 0;
}
