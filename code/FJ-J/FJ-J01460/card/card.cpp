#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m;
int a[N],last[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x=i;
		while(x<=n){
			ans[a[x]]++;
			x=last[a[x]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
