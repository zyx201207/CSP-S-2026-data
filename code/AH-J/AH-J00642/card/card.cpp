#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int a[500005],shiyanzu[500005],js[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		shiyanzu[i]=a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	int jj=0;
	for(int i=1;i<=n;i++){
		jj++;
		for(int j=n;j>=jj;j--){
			for(int k=j;k>=1;k--){
				if((shiyanzu[j]==shiyanzu[k])&&(shiyanzu[j]!=-1)){
					for(int pp=k+1;pp<=j;pp++){
						shiyanzu[pp]=-1;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(shiyanzu[j]==-1){
				continue;
			}
			js[shiyanzu[j]]++;
		}
		for(int j=1;j<=n;j++){
			shiyanzu[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++){
			cout<<js[i]<<" ";
	}
	}
	return 0;
}

