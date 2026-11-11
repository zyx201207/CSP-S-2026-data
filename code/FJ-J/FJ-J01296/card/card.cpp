#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];  
	}
	for(int i=1;i<=n;i++){
		int p=1;
		for(int j=n;j>max(p-1,i-1);j--){
			for(int k=j-1;k>max(p-1,i-1);k--){
				if(a[j]==a[k]){
					p=max(p,k+1);
					break;
				}
			}
		}
		for(int j=p;j<=n;j++){
			v[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
}
