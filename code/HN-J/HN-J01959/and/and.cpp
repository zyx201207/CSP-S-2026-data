#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
void ands(int t,int k,int sum){
	if (k==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=t-1;a[i]>ans;i--) ands(i,k+1,sum&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;a[i]>ans;i--) ands(i,1,a[i]);
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}
