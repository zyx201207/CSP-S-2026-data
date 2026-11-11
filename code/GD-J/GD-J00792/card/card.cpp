#include<bits/stdc++.h>
using namespace std;
int k,n,i,j,l,m;
int a[10000000],b[1000000],ans[10000000];
queue<int>q;
void cl(int k){
	for (int i=k;i<=n;i++){
		if(b[a[i]]==1){
			q.pop();
			
			while(q.front()!=a[i]&&q.size())q.pop();
			b[a[i]]=0;
		}
		q.push(a[i]);
		b[a[i]]=1;
	}
	while(q.size()){
		ans[q.front()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int e=1;e<=n;e++){
		for(i=1;i<=n;i++){
			b[a[i]]=0;
		}
		
		cl(e);
		
	}
	for (i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
