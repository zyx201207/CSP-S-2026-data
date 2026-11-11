#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
stack<int> sta;
bool st[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i])f=false;
	}
	if(f){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=max(cnt[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			printf("%d ",cnt[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
//		cout<<"i="<<i<<endl;
		memset(st,false,sizeof st);
		for(int j=i;j<=n;j++){
			if(!st[a[j]])sta.push(a[j]);
			else{
				while(sta.top()!=a[j]){
					st[sta.top()]=false;
					sta.pop();
				}
			}
			st[a[j]]=true;
		}
		while(!sta.empty()){
//			cout<<sta.top()<<" ";
			cnt[sta.top()]++;
			sta.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3

3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
 
*/
