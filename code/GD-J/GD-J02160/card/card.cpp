#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],card[500010],k,t[500010],pos[500010];
void start(){
	for(int i=1;i<=n;i++)card[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			if(card[pos[a[j]]]==a[j]&&pos[a[j]]<=k){
				k=pos[a[j]];
			}
			else{
				k++;
				card[k]=a[j];
				pos[a[j]]=k;
			}
		}
		for(int j=1;j<=k;j++){
			t[card[j]]++;
			card[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
