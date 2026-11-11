#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt[a[n]]==m;
	for(int z=1;z<=n;z++){
		bool h[300005]={0};
		h[a[n]]=1;
		int p=z;
		for(int i=1;i<=n;i++){
			for(int r=p;r<=i;r++){
				if(a[r]==a[i]){
					for(int j=r-1,k=i-1;j>=1;j--,k--){
						a[k]=a[j];
							p=k;
					}
				}
			}
		}
		for(int i=p;i<=n;i++){
			if(h[a[i]]==0){
				cnt[a[i]]++;
				h[a[i]]=1;
			} 
		}
	}
	for(int i=1;i<=300005;i++){
		if(cnt[i]!=0){
			cout<<cnt[i]<<" ";
		}
	}
	return 0;
}
