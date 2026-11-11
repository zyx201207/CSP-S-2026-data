#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,maxn=INT_MAX;
int a[N],ans;
bool vis[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=log2(a[i]+1);
		int k1=pow(2,k);
		if(k1!=a[i]) flag=false;
	}
	if(flag){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	do{
		int x=maxn;
		for(int i=1;i<=m;i++){
			x=x&a[i];
		}
		ans=max(ans,x);
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
} 
