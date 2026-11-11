#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int stk[200005]={};
		int l=0;
		for(int j=i;j<=n;j++){
			bool ok=1;
			for(int k=0;k<l;k++){
				if(stk[k]==a[j]){
					l=k+1;
					ok=0;
					break;
				}
			}

			if(ok){
				stk[l++]=a[j];
			}
			/*for(int k=0;k<l;k++){
				cout<<stk[k]<<' ';
			}
			cout<<'\n';*/
		}
		for(int j=0;j<l;j++){
			ans[stk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//24pt
