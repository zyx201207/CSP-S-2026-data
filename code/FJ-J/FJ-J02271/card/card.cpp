#include <bits/stdc++.h>
using namespace std;
long long num[300005];
int a[500005];
int flag[500005];
int pai[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		for(int i=1;i<=n;i++){
			flag[i]=0;
			pai[i]=0;
		}
		for(int i=n-q;i<=n;i++){
			if(flag[a[i]]==1){
				int y;
				for(int j=n-q;j<i;j++){
					if(a[j]==a[i]){
						y=j;
					}
				}
				for(int k=y;k<i;k++){
					if(pai[a[k]]!=0){
					flag[a[k]]=0;
						num[a[k]]--;
						pai[a[k]]=0;
					}
				}
			}
			flag[a[i]]=1;
			num[a[i]]++;
			pai[i]=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
