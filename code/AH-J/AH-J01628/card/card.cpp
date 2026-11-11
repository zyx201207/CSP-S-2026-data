#include<bits/stdc++.h>
using namespace std;
int p[500010],b[500010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	
	for(int i=1;i<=n;i++){
		int cp[500010]={0},cnt=0;
		for(int j=i+1;j<=n;j++){
			if(b[p[j]]==0){
				cp[cnt++]=p[j];
				b[p[j]]=j;
			}else{
				for(int k=b[p[j]];k<=j;k++){
					cp[k]=0;
				}
			}
		}
		for(int x=i+1;x<=n;x++){
			if(cp[x]!=0){
				c[cp[x]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
