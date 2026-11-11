#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],sheng[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int qwq[100001]={0},jei=1,cpp=0;
		for(int j=i;j<=n;j++){
			int yo=0;
			if(j==i)qwq[1]=a[i];
			for(int u=2;u<=jei;u++){
				if(qwq[u-1]==a[j]){
					cpp=1;
					yo=u;
				}				
				if(cpp){
					qwq[u]=0;
				}
			}
			if(j!=i){
				if(yo>0)jei=yo+1;
				else jei++;			
				qwq[jei]=a[j];				
			}

		}
		for(int kl=1;kl<=jei;kl++){
			sheng[qwq[kl]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sheng[i]<<" ";
	}
	return 0;
	
}
