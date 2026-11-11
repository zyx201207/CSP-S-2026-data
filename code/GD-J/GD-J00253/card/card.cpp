#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],d[300005],c[300005],sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]<=a[i]){
			sum++;
		}
	}
	if(sum==n){
		for(int i=n;i>=1;i--){
			if(!c[a[i]]){
				c[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(!c[a[i]]){
			c[a[i]]=i;
			b[i]=n+1;
		}else{
			b[i]=c[a[i]];
			c[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(b[j]<=n){
				j=b[j];
			}else{
				d[a[j]]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
