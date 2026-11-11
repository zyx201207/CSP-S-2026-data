#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,L,R,a[100005],ans[100005];
bool mp[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int t;
		cin>>a[i];
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}
 
