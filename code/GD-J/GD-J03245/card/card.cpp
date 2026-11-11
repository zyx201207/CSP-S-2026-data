#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
int mark[5005];
int mk[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(mk,0,sizeof(mk));
		for(int j=i;j<=n;j++){
			if(mk[a[j]]){
				memset(mk,0,sizeof(mk));
			}
			mk[a[j]]++;
		}
		for(int i=1;i<=m;i++){
			if(mk[i]){
				mark[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mark[i]<<' ';
	}
	return 0;
}
