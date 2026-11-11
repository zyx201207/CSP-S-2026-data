#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int b=m,j=i-1;
		for(;j>0;j--){
			b-=a[i]-a[j];
			if(b<0) break;
		}
		ans=max(ans,(long long)(i-j));
	}
	cout<<ans;
	return 0;
}

