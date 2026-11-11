#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u[200005];
		int tot=0;
		for(int j=1;j<=n;j++){
			for(int k=j-1;k>=1;k--){ //枚举和A[j]相等的A[k]，k<j 枚举到了直接把U数组J-K变成0 
				if(a[j]==a[k]){
					for(int h=j;h>=k;h--){
						u[h]=0;
					}
					tot=k-1;
					break;
				}
			}
			u[++tot]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(u[j]){
				t[u[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}

