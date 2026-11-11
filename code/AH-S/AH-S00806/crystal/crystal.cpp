#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1,tot=1,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	t=m;
	for(int i=2;i<=n;i++){
		while(tot*(a[i]-a[i-1])>t){
			tot--;
			t+=a[i]-a[i-tot];
		}
		t-=tot*(a[i]-a[i-1]);
		tot++;
		maxn=max(maxn,tot);
	}
	cout<<maxn;
	return 0;
}
