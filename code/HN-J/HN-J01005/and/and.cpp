#include <bits/stdc++.h>
using namespace std;
int a[200005],n,s,b[200005],ans=-1,y=0;
int dfs(int x){
	if (x==s){
		int sum=b[0];
		for (int i=1;i<x;i++){
		sum=(sum & b[i]);
		}
		ans=max(ans,sum);
		return 0;
	}
	for (int i=y;i<n;i++){
		if (x>=1 && i>y){
		b[x]=a[i];
		dfs (x+1);
		}
		else if (x<1){
		b[x]=a[i];
		dfs (x+1);
		}
	}
	y++;
}
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>s;
	for (int i=0;i<n;i++) cin>>a[i];
	dfs (0);
	cout<<ans;
}
