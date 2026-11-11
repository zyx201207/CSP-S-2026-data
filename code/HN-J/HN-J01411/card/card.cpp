#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],ans[M];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		b[i]=mp[a[i]];
		mp[a[i]]=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			while(b[j]!=j){
				j=b[j];
			}
			ans[a[b[j]]]++;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
