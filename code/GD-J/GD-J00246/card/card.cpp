#include<bits/stdc++.h>
using namespace std;
int lst[500005];
int a[500005];
int ans[500005];
bool check(int n){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
		if(lst[a[i]]==0)
			lst[a[i]]=i;
	if(check(n)){
		for(int i=1;i<=m;i++)
		 cout<<lst[i]<<" ";
		 return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
		    if(lst[a[j]]==j)ans[a[j++]]++;
		    else j=lst[a[j]];
		}		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

