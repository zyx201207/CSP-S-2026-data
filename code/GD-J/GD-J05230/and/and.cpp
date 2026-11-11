#include<bits/stdc++.h>
using namespace std;
int vis[10000086],a[1000005];
int n,m;
int maxn=0;
int cul(int k,int mn){
	if(k==m) return mn;
	int mn2=0,k1=0;
	for(int i=1;i<=n;i++){
		if(mn2<mn&a[i]&&vis[a[i]]==0){
			mn2=mn&a[i];
			k1=a[i];
		}
	}
	vis[k1]=1;
	return cul(k+1,mn2);
}
 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k1,k2;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(maxn<(a[i]&a[j])){
				maxn=(a[i]&a[j]);
				k1=a[i];
				k2=a[j];
			}
		}
	}
	vis[k1]=1;
	vis[k2]=1;
	cout<<cul(2,maxn);
	return 0;
}
