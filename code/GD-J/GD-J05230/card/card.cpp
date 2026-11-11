#include<bits/stdc++.h>
using namespace std;
int cnt[1000086],a[1000086];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int stk[1000086],s=0,instk[100086];
		memset(instk,m,0);
		for(int j=i;j<=n;j++){
			if(instk[a[j]]==1){
				while(stk[s]!=a[j]){
					instk[stk[s]]=0;
					stk[s--]=0;
				}
			}
			stk[s++]=a[j];
			instk[a[j]]=1;
		}
		for(int i=1;i<=m;i++){
			if(instk[i]==1){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}	 
	
	return 0;
}
