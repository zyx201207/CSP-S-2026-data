#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x;
int a[500005];
int ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int X=1;X<=n;X++){
		for(int i=X;i<=n;i++){
			ans[a[i]]++;
			for(int j=n;j>i;j--){
				if(a[j]==a[i]){
					i=j;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

