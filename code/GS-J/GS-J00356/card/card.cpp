#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int a[N],b[N];//b为当前数组
int c[N];//记录数第一次出现的位置 
int n,m;
int jiegou[5010];
int tot2;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]]=min(i,c[a[i]]);
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		if(i>1){
			for(int z=i;z<=n;z++){
				b[++tot]=a[z];
			}
		}
		for(int j=1;j<=n;j++){
			if(c[a[j]]==0){
				b[++tot]=a[j];
			}
			else{
				tot=c[a[j]];
				for(int k=tot+1;k<=n;k++){
					b[i]=0;
				}
			}
		}
		for(int d=1;d<=tot;d++){
			if(b[d]==i){
				jiegou[i]++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jiegou[i]<<' ';
	}
	return 0;
}
