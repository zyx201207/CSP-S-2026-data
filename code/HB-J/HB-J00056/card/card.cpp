#include<bits/stdc++.h>
using namespace std;
queue<int> qu;
int n,m;
int ans[600000];
int a[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
