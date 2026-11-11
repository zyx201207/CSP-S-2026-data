#include<bits/stdc++.h>
using namespace std;
int a[1000090];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++) s=s&a[i];
		cout<<s;
		return 0;
		}
	return 0;
}
