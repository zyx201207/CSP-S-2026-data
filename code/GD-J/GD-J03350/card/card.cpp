#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0,c[n]; 
		for(int j=i-1;j<n;j++){
			c[cnt]=a[j];
			cnt++;
			for(int x=cnt-1;x>=i-1;x--){
				if(c[x]==c[cnt]) cnt=x+1;
			}
		}
		for(int y=i-1;y<=cnt;y++){
			ans[c[y]-1]++;
		} 
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0; 
} 
