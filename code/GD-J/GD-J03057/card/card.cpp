#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

int n,m,a[N],t[N],res[N];
bool vis[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof vis);
		int idx = 0;
		for(int j=i;j<=n;j++){
			if(vis[t[j]]){
				int tt = idx;
				for(int k=1;k<idx;k++){
					if(t[k]==t[j]){
						idx = k;
						break;
					}
				}
				for(int k=idx+1;k<=tt;k++){
					vis[t[k]] = false;
				}
				t[++idx] = t[j];
			}
			else{
				t[++idx] = a[j];
				vis[t[idx]] = true;
			}
		}
		for(int j=1;j<=idx;j++){
			res[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
