#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t=0,maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1,j=1;j<=n;j++){
		t+=(j-i)*(a[j]-a[j-1]);
		while (t>m){
			t-=(a[j]-a[i]);
			i++;
		}
		if (i!=j){
			if (maxx<j-i+1) maxx=j-i+1;
		}
	}
	cout<<maxx;
	return 0;
}
