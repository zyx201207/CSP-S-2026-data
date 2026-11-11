#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,a[500005],ans[100005],l=1,maxn,p=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			l=0;
		}
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			p=0;
		}
	}
	if(l==1){
		for(LL i=1;i<=n;i++){
			if((1+i)*i/2>m){
				cout<<i;
				exit(0);
			}
		}
	}
	if(p==1){
		LL v=a[2]-a[1];
		for(LL i=2;i<=n;i++){
			if(i*(i-1)/2*v>m){
				cout<<i-1;
				exit(0);
			}
		}
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++){
		LL k=0,l=i;
		for(LL j=i+1;j<=n;j++){
			k+=(j-l)*(a[j]-a[l]);
			if(k<=m){
				maxn=max(maxn,j-i+1);
			}
			l++;
		}
	}
	cout<<maxn;
}
