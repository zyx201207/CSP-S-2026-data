#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int be[500005];
int st[500005];
int ans[300005];
int top=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=m;j++){
			be[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(be[a[j]]==0){
				st[++top]=a[j];
				be[a[j]]=top;
			}else{
				for(int v=be[a[j]]+1;v<=top;v++){
					be[st[v]]=0;
				}
				top=be[a[j]];
			}
		}
		for(int j=1;j<=top;j++){
			ans[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
