#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],last[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],last[a[i]]=i;
	for(int i=1;i<=n;i++){
		int l=i,r=last[a[i]];
		while(l<=r&&r<=n){
			sum[a[l]]++;
			l=r+1,r=last[a[l]]; 
		}
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
} 
