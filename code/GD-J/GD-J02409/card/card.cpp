#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],desk[500005],pos[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int i=1;i<=n;i++) {
			desk[i]=0;
			pos[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(pos[a[j]]){
				for(int k=pos[a[j]];k<=j;k++) {
					desk[k]=0;
					pos[a[k]]=0;
				}
				desk[pos[a[j]]]=a[j];
			}
			else{
				desk[j]=a[j];
				pos[a[j]]=j;
			} 
		}
		for(int j=1;j<=m;j++) {
			if(pos[a[j]]) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
