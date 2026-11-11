#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-999;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}
		cout<<maxn;
	}
	int sum=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	return 0;
}
