#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn=2e5+5;
int vis[maxn];//点数i在桌上位置,无则为0; 
int ans[maxn];//点数i在每局尾出现次数;
int s[maxn];
int t[maxn];
int n,m;
bool flag=1;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]<s[i-1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			ans[s[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		int id=1;//最右;
		for(int j=i;j<=n;j++){
			t[id]=s[j];
			id++;
			if(vis[t[id]]!=0){
				for(int k=vis[s[j]];k<=id;k++){
					t[k]=0;
					vis[t[k]]=0;
				}
				id=vis[t[id]]-1;
			}
			vis[t[id]]=id;
		}
		for(int j=1;j<=id;j++){
			ans[t[id]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

