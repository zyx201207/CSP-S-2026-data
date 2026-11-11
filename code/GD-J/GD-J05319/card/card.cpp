#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=n;k>=i;k--){
				if(a[j]==a[n]){
					j=k;
					ans[a[j]]++;
//					cout<<a[j]<<" ";
					cnt=k;
					break;
				} 
			} 
			if(j!=cnt){
				ans[a[j]]++;
//				cout<<a[j]<<" ";
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
