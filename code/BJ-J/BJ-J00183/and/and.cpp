#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=0,maxn=0,maxq=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	maxn=a[1];
	if(m==1){
		cout<<maxx;
		return 0;
	}
	
	if(m==n){
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				maxq=max(maxq,t);
			}
		}
		cout<<maxq;
		return 0;
	}
	return 0;
}
