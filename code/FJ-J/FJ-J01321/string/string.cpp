#include <bits/stdc++.h>
#define int long long
using namespace std;
int pre[1000000];
char x[1000000];
int a[1000000];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cin>>x[i];
		pre[i]=pre[i-1]+a[i];
	} 
	for(int i=1;i<=pre[n]/2;++i){
		int s=i,e=pre[n]-i+1;
		char aa,bb;
		for(int j=1;j<=n;++j){
			if(pre[j-1]<=s&&pre[j]>=s){
				aa=x[j];
				break;
			}
		}
		for(int j=n;j>=1;--j){
			if(pre[j-1]<=e&&pre[j]>=e){
				bb=x[j];
				break;
			}
		}
		if(aa!=bb)ans++;
	}
	cout<<ans;
	return  0;
}
