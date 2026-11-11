#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int p[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		memset(p,0,sizeof(p));
		int op=1;
		for(int i=1;i<=n;i++){
			int f=0;
			for(int j=i-1;j>=1;j--){
				if(p[j]==a[i]){
					f=j;
					for(int k=j;k<=i;k++){
						p[k]=0;
					}
				}
			}
			if(f!=0){
				op=f;
				p[op]=a[i];
			}
			else{
				p[i]=a[i]; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
