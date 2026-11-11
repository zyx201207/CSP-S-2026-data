#include <bits/stdc++.h>
using namespace std;

int n,m;
int cds[500010],cap[300010],nw[500010];;

int fd(int a){
	for(int i=0;i<n;i++){
		if(nw[i]==a){
			return i;
		}
		if(nw[i]==0){
			return 0;
		}
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cds[i];
	}
	memset(cap,0,sizeof(cap));
	for(int i=1;i<=n;i++) {//iÎª¾ÖÊý 
		
		memset(nw,0,sizeof(nw));
		for(int j=i;j<=n;j++){
			int fa=fd(cds[j]);
			if(fa>0){
				for(int p=fa;p<n;p++){
					cap[nw[p]]--;
					nw[p]=0;
				}
			}else{
				nw[j]=cds[j];
				cap[j]++;
			}
			
		}
	}
	for(int i=0;i<m;i++){
		cout<<cap[i]<<" ";
	}
	return 0;
}
