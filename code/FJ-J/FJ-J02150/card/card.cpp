#include <bits/stdc++.h>
using namespace std;
int a[500005],zm[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int xb=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=xb;k++){
				if(zm[k]==a[j]){
					for(int l=k;l<=xb;l++)zm[l]=0;
					xb=k;
					break;
				}
			}
			xb++;
			zm[xb]=a[j];
		}
		for(int j=1;j<=xb;j++){
			ans[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
