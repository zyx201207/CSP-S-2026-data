#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],vis[300009],l[300008],r[300009];
map<int,int>idx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
	}
	/*for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>alive;
	for(int i=n;i>0;i--){
		alive.push(a[i]);
		while(idx[a[i]]<alive.size()){
			if(l[alive.top()])vis[alive.top()]+=l[alive.top()]-r[alive.top()]+1;
			l[alive.top()]=r[alive.top()]=0;
			r[a[i]]=alive.size();
			if(alive.size())alive.pop();
		}
		l[a[i]]=alive.size();
		idx[a[i]]=alive.size();
	}
	while(alive.size()){
		cout<<alive.top()<<endl;
		alive.pop();
	}
	for(int i=1;i<=m;i++){
		vis[i]+=l[i]-r[i]+1;
		cout<<vis[i]<<" ";
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
