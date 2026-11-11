#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		int b[500010]={0},k=0,p;
		for(int j=q;j<=n;j++){
			p=-1;
			for(int i=1;i<=k;i++){
				if(a[j]==b[i]){
					p=i;
					break;
				}
			}
			if(p!=-1){
				k=p;
			}else{
				b[++k]=a[j];
			}
		}
		for(int i=1;i<=k;i++){
			vis[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}
