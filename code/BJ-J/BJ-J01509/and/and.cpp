#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1) cout<<a[n];
	int ans=0;
	int k=1;
	while(k){
		int cnt=a[k];
		for(int i=k+1;i<=n-m-k+1;i++){
			cnt=cnt&a[i];
		}
		ans=max(ans,cnt);
		if(k==n-m-k+1) break;
		k++;
	}
	cout<<ans;
	return 0;
}
