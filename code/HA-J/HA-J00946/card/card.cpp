#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300005];
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i+1;
		while(r<n){
			if(a[l]!=a[r]){
				r++;
			}else{
				l=r;
				r++; 
			}
		}
		int cnb[300005]={};
		for(int j=l;j<=r;j++){
			if(cnb[a[j]]!=0){
				continue;
			}else{
				cnt[a[j]]++;
				cnb[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]!=0){
			cout<<cnt[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

