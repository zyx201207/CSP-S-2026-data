#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,k,a[N],ans=-1e9;
void dfs(int i,long long sum,int cnt){
	if(i==n){
		if(cnt==k){
			ans=max(ans,sum);
		}
		return;
	}
	if(cnt==k){
		ans=max(ans,sum);
		return;
	}
	dfs(i+1,sum&a[i],cnt+1);
	dfs(i+1,sum,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-k;i++){
		dfs(i+1,a[i],1);
	}
	cout<<ans;
    return 0;
}

