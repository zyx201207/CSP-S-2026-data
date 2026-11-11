#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> ka(n+1),num(m+1);
	vector<int> cor(m+1);
	for(int i=1;i<=n;i++) cin>>ka[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int a=ka[j];
			if(cor[a]){
				for(int k=cor[a];k<=j;k++) cor[ka[k]]=0;
			}
			cor[a]=j;
		}
		for(int i=1;i<=m;i++){
			if(cor[i]) num[i]++;
			cor[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
} 
