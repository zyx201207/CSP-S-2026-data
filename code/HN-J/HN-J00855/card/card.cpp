#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,m;
int tim[N];
int cnt[N];
int lst[N];
int a[N];
ll ans[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) lst[a[i]]=i;
	for(int i=1;i<=n;i++){
		if(i!=lst[a[i]]) cnt[lst[a[i]]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;			
			j=lst[a[j]];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

