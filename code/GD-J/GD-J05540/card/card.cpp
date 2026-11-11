#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,w[10005],f[10005],cnt[30005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		ll to=0,ba=0;
		for(int j=1;j<=n;j++){
			f[i]=w[i];
			cnt[i]++;
		}
		for(int j=1;j<=m;j++){
			if(w[j]=i){
				to=j;
				break;
			}
		}
			for(int j=m;j>=1;j--){
			if(w[j]=i){
				ba=j;
				break;
			}
		}
		for(int j=to;j<ba;j++){
			cnt[w[j]]--;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
