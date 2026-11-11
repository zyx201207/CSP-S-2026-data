#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],nextai[500005],vis[300005];
int veclast[300005],vecuse[300005];
long long veccnt[300005];
int inter[300005];
long long ans[300005];
queue<int> que;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		nextai[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(!nextai[i]){
			veclast[a[i]]=vecuse[i+1];
			inter[vecuse[i+1]]++;
			vecuse[i]=a[i];
			veccnt[vecuse[i]]++;
		}
		else{
			vecuse[i]=vecuse[nextai[i]];
			veccnt[vecuse[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(!inter[i]){
			que.push(i);
		}
	}
	while(que.size()){
		int t=que.front();
		que.pop();
		ans[t]+=veccnt[t];
		if(!veclast[t]){
			continue;
		}
		veccnt[veclast[t]]+=veccnt[t];
		inter[veclast[t]]--;
		if(!inter[veclast[t]]){
			que.push(veclast[t]);
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
