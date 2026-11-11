#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans[300001];
bool flag[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int l=k;l<=j-1;l++){
						flag[l]=1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!flag[j]){
				ans[a[j]]++;
			}
			flag[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
