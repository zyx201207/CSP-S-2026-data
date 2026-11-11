#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	int stk[500010],top=0;
	for(int i = 1;i <= n;i ++){
		top=0;
		for(int j = i;j <= n;j ++){
			for(int k = 1;k <= top;k ++){
				if(stk[k]==a[j]){
					top=k-1;
					break;
				}
			}
			top++,stk[top]=a[j];
		} 
		for(int j = 1;j <= top;j ++) t[stk[j]]++;
	}
	for(int i = 1;i <= m;i ++) cout<<t[i]<<' ';	
}
