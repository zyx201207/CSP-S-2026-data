#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];	
bool b[500005];
int nw[500005];
int ans[500005];
int r[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==false){
			b[a[i]]=true;
			r[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=r[a[i]];j<=n;j++){
			if(r[a[j]]!=j){
				j=r[a[j]];
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
             