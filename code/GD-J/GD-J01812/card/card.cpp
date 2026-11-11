#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],tmp[500005],ans[300005];
void check(int l){
	//加牌去牌环节 
	for(int i=l;i<=n;i++){
		if(tmp[i]!=0){
			for(int j=l;j<i;j++){
				if(tmp[i]==tmp[j]){
					for(int k=j;k<=i;k++){
						tmp[k]=0;
					}
					tmp[i]=tmp[j];
					break;
				}
			}
		}
	}
	//计算留了什么牌
	for(int i=1;i<=n;i++){
		if(tmp[i]==0)continue;
		ans[tmp[i]]++;
	} 
	//结束之后恢复数组tmp
	for(int i=l;i<=n;i++){
		tmp[i]=a[i];
	} 
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		check(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
