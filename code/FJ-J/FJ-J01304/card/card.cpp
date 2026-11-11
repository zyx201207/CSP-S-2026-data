#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5;
int n,m;
int a[N+5];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(a[x]==0){
			a[x]=i;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<n-a[i]+1<<" ";
	}
	return 0;
}
