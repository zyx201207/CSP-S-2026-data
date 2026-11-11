#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans[300005],yes[300005],k[500005],shu=0;
void js(long long x){
	for(long long i=n;i>=x;i--){
		if(a[i]==a[x]){
			ans[a[i]]++;
			js(i+1);
			break;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=n;i>=1;i++){
		js(i);
	}
	for(long long j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
