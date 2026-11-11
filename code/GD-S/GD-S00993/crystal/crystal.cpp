#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],minn=1e12,maxx;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(a[i],minn);
	}	
	for(int i=1;i<=n;i++){
		long long s=0,k=m;
		if(a[i]!=minn){
			for(int j=1;j<=n;j++){
				if(a[j]==a[i]){
					s++;
					continue;
				}
				if(a[j]<=a[i]&&k-a[i]+a[j]>=0){
					s++;
					k=k-a[i]+a[j];
				}
			}
		}
		maxx=max(s,maxx);
	}
	cout<<maxx;
	return 0;
} 
