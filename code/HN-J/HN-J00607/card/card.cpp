#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],a1[500005];
bool vis[300005];
void f(int i){
	for(int j=i;j<=n;j++){
		if(vis[a1[j]]){
			for(int k=j-1;k>=0;k--){
				if(a1[k]==a1[j]){
					a1[k]=0;
					break;
				}
				vis[a1[k]]=0;
				a1[k]=0;
			}
		}else vis[a1[j]]=1;
	}
	for(int j=i;j<=n;j++){
		b[a1[j]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
		for(int i=1;i<=n;i++){
			a1[i]=a[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	
	return 0;
} 
