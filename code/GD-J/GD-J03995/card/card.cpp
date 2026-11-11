#include<bits/stdc++.h>
using namespace std;
queue<long long> q;
long long n,m,nw=1;
 long long nn[500010];
 long long mm[300010];
 long long id[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nn[i];
	}
	while(nw<=n){
	long long idx=1;
		for(int i=nw;i<=n;i++){
			if(id[nn[i]]!=0){
				for(int j=1;j<idx-id[nn[i]];j++){
					q.pop();
				}
				idx=id[nn[i]];
			}
			q.push(nn[i]);
		    id[nn[i]]=idx;
			idx++;	
		}
		while(!q.empty()){
			mm[q.front()]++;
			q.pop();
		}
		nw++;
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}
	cout<<'\n';
	return 0;
} 
