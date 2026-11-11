#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[j]=1;
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[j-1]){
				t[a[j-1]]=0;
			}
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]==1){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
