//GZ-S00128 贵阳市第一中学 赵志杰
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,k,c,t,num;
vector<int> a[MAXN];
bool vist[MAXN];
void dfs(int now,int dep){
	vist[now]=1;
	num++;
	if(dep==0)return;
	for(int i=0;i<a[now].size();i++){
		int l=a[now][i];
		if(!vist[l])dfs(l,dep-1);
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	//if(c==0)return 0;
	while(t--){
		
		priority_queue<int> s;
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=0;i<n;i++){
			s.push(a[i].size());
		}
		int num;
		num+=s.top();
		s.pop();
		num+=s.top();
		if(num>=k){
			printf("1\n");
			continue;
		}
		while(!s.empty()){
			s.pop();
		}
		for(int i=2;i<n-1;i++){
			for(int j=0;j<n;j++){
				dfs(j,i);
				s.push(num);
				num=0;
				memset(vist,0,sizeof(vist));
			}
			int as=0;
			as+=s.top();
			s.pop();
			as+=s.top();
			if(as>=k){
				printf("%d\n",i);
				memset(a,0,sizeof(a));
				num=0;
				continue;
			}
		}
		printf("%d\n",n-1);
		memset(a,0,sizeof(a));
		num=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
