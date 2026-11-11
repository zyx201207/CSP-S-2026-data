#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int a[N],cnt[N],cntt[N];
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	freopen("card.out","w",stdout);
	int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cntt[j]=cnt[j];
		for(int j=1;j<i;j++)cntt[a[j]]--; 
		for(int j=i;j<=n;j++){
			if(cntt[a[j]]==1)ans[a[j]]++,cntt[a[j]]--;
			if(cntt[a[j]]>1){
				int k=j+1;
				cntt[a[j]]--;
				while(a[k]!=a[j]&&k<=n){
					cntt[a[k]]--;
					k++;
				}
				//cntt[a[k]]++;
				j=k-1;
			}
		}
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
/*
4 3 
1 2 1 3
*/
