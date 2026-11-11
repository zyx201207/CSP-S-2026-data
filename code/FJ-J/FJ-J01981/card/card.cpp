#include<iostream>
#include<cstring>
using namespace std;
int ans[300005],n,m,a[500005],tmp[500005],longofa,left;
bool flag=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&tmp[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			for(int k=1;k<=longofa;++k){//判断重复 
				if(tmp[j]==a[k]){
					flag=false;
					longofa-=(longofa-k);
					a[longofa]=tmp[j];
					break;
				}
			}
			if(flag){
				longofa++;
				a[longofa]=tmp[j];
			}
			flag=true;
		}
		for(int j=1;j<=m;++j){
			ans[a[j]]++;
		}
		longofa=1;

		memset(a,0,sizeof(a));
	}
	for(int i=1;i<=m;++i){
		printf("%d ",ans[i]);
	}
	return 0;//freopen结束前注释要删掉！！！ 并保存！！！ 
}
