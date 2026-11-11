#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],su[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool t=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])t=false;
	}
	if(t){
		for(int i=1;i<=n;i++){
			for(int k=i;k<=n;k++){
				ans[a[k]]++;
				if(a[k]==a[k-1]){
					ans[a[k]]--;
					ans[a[k-1]]--;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int k=i;k<=n;k++){
				for(int j=i;j<=k;j++){
					if(a[j]==a[k]){
						su[j]=1;
					}if(su[j-1]==1)su[j]=1;
				}
				for(int j=i;j<=k;j++){
					if(su[j]==0){
						ans[a[j]]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
