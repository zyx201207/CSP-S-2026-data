#include<bits/stdc++.h>
using namespace std;
int m,cards[500002],table[300002],n,ans[300002],k=0,l,mx=-1;
bool an[300002];
int check(int p){
	for(l=1;l<=k;l++){
		if(table[l]==p)return l;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(cards[j])){
				for(int o=l;o<=k;o++){
					table[o]=0;
				}
				k=l-1;
			}
			k+=1;
			table[k]=cards[j];
		}
		mx=-1;
		for(int j=1;j<=k;j++){
			an[table[j]]=true;
			if(table[j]>mx)mx=table[j];
		}
		for(int j=1;j<=mx;j++){
			if(an[j]){
				ans[j]++;
			}
		}
		for(int j=1;j<=m;j++){
			an[j]=false;
			table[j]=0;
		}
		k=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
