#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int cnt[N];
int ans[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1] && i>1) ok=0;
	}
	if(ok==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]=i;
			}
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		} 
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
