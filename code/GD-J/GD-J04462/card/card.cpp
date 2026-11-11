#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N];
int bro[N];
int pla[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(bro,0,sizeof(bro));
		memset(pla,0,sizeof(pla));
		for(int j=i;j<=n;j++){
			if(!pla[a[j]]||bro[pla[a[j]]]){
				pla[a[j]]=j;
			}else{
				for(int k=pla[a[j]];k<=j-1;k++){
					bro[k]=1;
				}
				pla[a[j]]=j;
			}
			//for(int k=1;k<=m;k++)cout<<pla[k]<<' ';
			//cout<<endl;
		}
		for(int j=1;j<=m;j++){
			if(!bro[pla[j]]&&pla[j]){
				ans[j]++;
			}
			//cout<<ans[j]<<' ';
		}
		///cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
