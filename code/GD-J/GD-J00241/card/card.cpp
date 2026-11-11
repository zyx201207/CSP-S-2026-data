#include<bits/stdc++.h>
using namespace std;
int use[50001][30001];
int ds[50001];
long long out[30001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	//vector<int> msum(m);
	for(int i = 1;i<=n;i++){
		cin >> ds[i];
	}
	for(int i = 1;i<=n;i++){
		int nds[n+5];
		int ndssize = 0;
		for(int j = i;j<=n;j++){
			if(use[i][ds[j]]==0){
				nds[ndssize] = ds[j];
				ndssize++;
				use[i][ds[j]] = ndssize;
				out[ds[j]]++;
			} else{
				for(int k = use[i][ds[j]];k<=ndssize;k++){
					use[i][nds[k]] = 0;
					out[nds[k]]--;
					ndssize--;
				}
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout << out[i] << " ";
	}
}
