#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long a[N]={0},sum[N]={0};
int n,m,ans;
long long max(long long a,long long b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		sum[i]=a[i];
		for(int j=i+1;j<=m;j++){
			sum[i]&=a[j];
		}
		ans=max(sum[i],ans);
	}
	
	cout<<ans;
	return 0;
}
