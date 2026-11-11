#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int a[N],ans[N],vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	bool f=1;
	//sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]){
				f=0;
				break;
			}
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	return 0;
} 
