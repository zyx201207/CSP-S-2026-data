#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans[500005];
int finding(int x){
	int i=n;
	while(a[i]!=x)i--;
	return i;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ed;
	for(int p=1;p<=n;p++){
		ed=n;
		for(int i=p;i<=n;i++){
			if(i!=finding(a[i])){
				ed=min(ed,finding(a[i])-1);
			}
		}
		for(int i=p;i<=ed;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}  
