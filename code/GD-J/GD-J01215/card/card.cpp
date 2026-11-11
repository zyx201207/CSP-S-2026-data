#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[514514];
int pre[514514];
int nex[514514];
long long RP[514514];
long long ans[514514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n-i+1];
	}for(int i=1;i<=n;i++){
		if(!pre[a[i]]){
			pre[a[i]]=i;
		}nex[i]=pre[a[i]]-1;
	}for(int i=1;i<=n;i++){
		RP[i]++;
	}for(int i=n;i>=1;i--){
		RP[nex[i]]+=RP[i];
	}for(int i=1;i<=n;i++){
		ans[a[i]]+=RP[i];
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
