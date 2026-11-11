#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],res[500005],pz[500005],bj[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=i;j<=n;j++){
			if(bj[a[j]]==0){
				bj[a[j]]++;
				k++;
				pz[k]=a[j];
			}else{
				int iop=0;
				for(int x=1;x<=k;x++){
					if(pz[x]==a[j]){
						iop=x;
						break;
					}
				}
				for(int p=iop+1;p<=k;p++){
					bj[pz[p]]--;
					pz[p]=0;
				}
				k=k-(k-iop);
			}
		}
		for(int j=1;j<=k;j++){
			res[pz[j]]++;
		}
		for(int j=1;j<=k;j++){
			pz[j]=0;
		}
		for(int j=1;j<=m;j++){
			bj[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
