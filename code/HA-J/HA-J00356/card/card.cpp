#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int v[100010];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int top=0;
	for(int i=0;i<n;i++){
		int st[100010]={0};
		int x;
		cin>>x;
		bool flag=0;
		if(top==0){
			v[1]=x;
			top++;
			flag=1;
		}
		if(flag==0){
			for(int j=1;j<=top;j++){
				if(v[j]==x){
					top=j;
					flag=1;
					break;
				}
			}
		}
		
		if(flag==0){
			top++;
			v[top]=x;
		}
		for(int j=1;j<=top;j++){
			if(st[v[j]]==0){
				ans[v[j]]++;
				st[v[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}