#include<bits/stdc++.h>
using namespace std;
int pai[500005],pai2[500005],shu[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
	for(int i=1;i<=n;i++){
		pai[i-1]=0;
		for(int j=1;j<=n;j++){
			pai2[j]=pai[j];
		}
		for(int j=n;j>i;j--){
			if(pai2[j]==pai2[i]){
				for(int x=i;x<j;x){
					pai2[x]=0;
					x++;
				}		
			}	
		}
		for(int j=1;j<=n;j++){
			if(pai2[j]>0){
				shu[pai2[j]]++;
			}
		}		
	}
	for(int i=1;i<=m;i++){
		cout<<shu[i]<<" ";
	}
}
