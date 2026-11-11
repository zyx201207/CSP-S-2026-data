#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],n,m,ans,sum[N];
int check(int node){
	int k=m,i=node-1,j=0;
	for(;i;i--,j++){
		k-=a[node]-a[i];
		if(k<0){
			if(j>1)return j;
			else return 0;
		}
	}
	if(node>1)return node;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
}
