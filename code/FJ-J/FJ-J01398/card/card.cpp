#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],c[500005],ans[3005],ne[3005],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	for(int i=1;i<=n;i++){
		memset(ne,0,sizeof(ne));
		top=0;
		for(int j=i;j<=n;j++){
			if(ne[arr[j]]){
				while(c[top]!=arr[j]){
					ne[c[top]]=0;
					top--;
				}
				ne[c[top]]=0;
				top--;
			}
			
			c[++top]=arr[j];
			ne[arr[j]]=1;
		}
		for(int j=1;j<=top;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
