#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,c;
	cin>>n>>m;
	int times[m+5];
	int card[n+5];
	int l[m+5]={0};
	int r[m+5]={0};
	
	for(int i=1;i<=n;i++){
		cin>>card[i];
//		for(int j=1;j<=i;j++){
//			if(card[j]>=card[i]){
//				times[card[j]]++;
//			}
//		}
	}
	for(int i=1;i<=n;i++){
		if(l[card[i]]==0) l[card[i]]=i;
		if(card[i]<card[i+1]) r[card[i]]=i; 
	}
	r[m]=n;
//	for(int i=1;i<=m;i++) cout<<l[i]<<" "<<r[i]<<"\n";
	for(int i=1;i<=m;i++) cout<<n-l[i]+1<<" ";
	return 0;
} 
