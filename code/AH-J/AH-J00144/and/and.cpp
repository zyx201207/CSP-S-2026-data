#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005];
int ans=0,maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	ans=a[1];
	for(int i=2;i <= n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		ans|=a[i];
	}
	if(m==n)cout<<ans;
	else if(m==1){
		cout<<maxn;
	}else if(m==2){
		maxn=0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				maxn=max(maxn,a[i]|a[j]);
			}
		}
		cout<<maxn;
	}else{
		cout<<maxn;
	}
	return 0;
}
