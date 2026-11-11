#include<bits/stdc++.h>
using namespace std;
int n,m,pa[500005],x;
bool book[500005],yo[300005];
long long ans[300005];
stack<int> zhu;
int main(){
	freopen("crad.in","r",stdin);
	freopen("crad.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&pa[i]);
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		for(int j=1;j<=m;j++) yo[j]=false;
		for(int x=i;x<=n;x++){
			if(!yo[pa[x]]){
				zhu.push(pa[x]);
				yo[pa[x]]=true;
				continue;
			}
			while(zhu.top()!=pa[x]){
				yo[zhu.top()]=false;
				zhu.pop();
			}
		}
		while(!zhu.empty()){
			int nw=zhu.top();
			zhu.pop();
			ans[nw]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
} 
