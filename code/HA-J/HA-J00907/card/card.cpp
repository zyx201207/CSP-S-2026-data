#include<bits/stdc++.h>
using namespace std;
int a[500005];
int p[500005];
int f[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=max(p[a[i]],i);
	}

	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;){
			ans[a[i]]++;
			i=p[a[i]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0; 
}

