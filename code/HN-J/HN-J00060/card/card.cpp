#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t[100005];
bool vis[100005];
void hw(int start){
	memset(vis,0,sizeof(vis));
	for(int i=start;i<=n;i++){
		for(int j=start;j<i;j++){
			if(a[i]==a[j]&&vis[j]==0){
				for(int k=j;k<i;k++){
					vis[k]=1;
				}
			}
		} 
	}
	for(int i=start;i<=n;i++){
		if(vis[i]==0)t[a[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		hw(i);
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 
/*
游记？ 
关注Hamster_Emperor谢谢喵
红（分支结构）橙（字符串）橙（排序，贪心）黄（模拟）今年分数线300+？ 
T4不想打正解了
100+100+100+48 
*/ 
