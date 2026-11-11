#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],d[500050],ans[300050],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(500<n<=5000){
		for(int i=1;i<=n;i++){
			cnt=1;
			d[cnt++]=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[j]!=a[j-1]) d[cnt++]=a[j];
			}
			for(int j=1;j<cnt;j++){
				ans[d[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=i;j<=n;j++){
			int k;
			for(k=1;k<cnt;k++){
				if(d[k]==a[j]) break;
			}
			if(d[k]==a[j]){
				cnt=k;
				d[cnt++]=a[j];
			}else{
				d[cnt++]=a[j];
			}
		}
		for(int j=1;j<cnt;j++){
			ans[d[j]]++;
		}
	}	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
