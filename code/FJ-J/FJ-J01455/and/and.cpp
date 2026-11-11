#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1,k[200005];
void f1(int dep,int ans){
	if(dep==m){
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!k[i]){
			k[i]=1;
			f1(dep+1,ans&a[i]);
			k[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	}else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}else{
		for(int i=1;i<=n;i++){
			k[i]=1;
			f1(1,a[i]);
			k[i]=0;
		}
		cout<<maxn;
	}
	
	return 0;
}
