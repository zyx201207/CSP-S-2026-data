#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int pos[500005];
int aa[500005];
void init(){
	for(int i=1;i<=n;i++){
		a[i]=aa[i];
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]=a[i];
	}
	
	for(int i=1;i<=n;i++){//游戏次数 
		init();
		memset(pos,0,sizeof(pos));
		bool f=0;
		for(int j=i;j<=n;j++){//当前牌的位置，a[j]:当前牌点数 
			int jj;
			if(!f) jj=j;
			else a[++jj]=a[j],a[j]=0;
			if(pos[a[jj]]!=0){
				a[pos[a[jj]]]=a[jj];
				for(int k=pos[a[jj]]+1;k<=jj;k++){
					a[k]=0;
				}
				jj=pos[j]+1,f=1;
			}else {
				pos[a[j]]=j;
			}
		}

		for(int j=i;j<=n;j++){
			if(a[j]!=0){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
