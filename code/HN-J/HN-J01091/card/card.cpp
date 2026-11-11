#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000000],zhuo[5000000],ans[5000000];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			for(int q=1;q<k;q++){
				if(zhuo[q]==a[j]){
					k=q;
				}
			}
			zhuo[k++]=a[j];
		}
		for(int j=1;j<k;j++){
			ans[zhuo[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

