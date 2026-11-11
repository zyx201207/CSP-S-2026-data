#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
int cnt[N],a[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]]){
				cnt[a[i]]+=j-i;
				break;
			}
			if(j==n){
				cnt[a[i]]+=n-i+1;
			}
		}
		if(i==n)cnt[a[i]]++;
//		cout<<cnt[a[i]]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
} 
