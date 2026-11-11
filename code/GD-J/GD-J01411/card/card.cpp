#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,pai[N],pz[N],k,lp[N],lpi;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	if(m==1){
		cout<<"1 1 1";
		return 0;
	}
	
	for(int i=0;i<n;i++) cin>>pai[i];
	
	for(int i=0;i<n;i++){
		lpi=0;
		for(int j=i;j<n;j++){
			if(pai[j]==k){
				memset(&pz,0,sizeof pz);
				pz[j]==pai[j];
			} 
			pz[j]=pai[j];
			if(j==i&&i==0)k=pai[j];
		}
		for(int j=0;j<n;j++){
			if(pz[j]!=0){
				for(int l=1;l<=m;l++){
					if(pz[j]==l){
						lp[lpi++]=i;
					}
				}
			}
		}
	}
	for(int i=0;i<m;i++)cout<<lp[i]<<" ";
	return 0;
}
