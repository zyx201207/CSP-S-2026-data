#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
struct node{
	int t,Last;
}nod[500010];
int ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nod[j].t=0;
			nod[j].Last=0;
		}
		for(int j=i;j<=n;j++){
			nod[a[j]].t++;
			if(nod[a[j]].t>=2){
				for(int k=nod[a[j]].Last;k<j;k++){
					nod[a[k]].t=0;
					nod[a[k]].Last=0;
				}
			}
			nod[a[j]].t=1;
			if(nod[a[j]].t==1){
				nod[a[j]].Last=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(nod[j].t==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
