#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;cin>>n>>m;int a[n];
	for(int& x:a)cin>>x;
	sort(a,a+n);ans=a[n-1];
	if(m==n-1){
		int res=-1016124;
		for(int i=0;i<n;i++){
			(i==0)?ans=a[i]:ans=a[0];
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ans=ans&a[j];
			}
		}res=max(res,ans);
		cout<<res;return 0;
	}
	for(int i=n-2;i>=n-m;i--)ans=ans&a[i];
	cout<<ans;
	return 0;
}
