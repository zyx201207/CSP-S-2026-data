#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		sum[a[i]]+=i;
		if(i==n)sum[a[i]]=i;
		if(p[a[i]]!=i){
			for(int j=i;j<p[a[i]];j++){
				sum[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
