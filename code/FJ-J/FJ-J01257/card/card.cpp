#include<bits/stdc++.h>
using namespace std;
int n,m;
bool f;
int a[500005];
int ans[300005];
queue<int> q;
void cow(int x){
	queue<int> p;
	while(!q.empty()){
		if(x==q.front()){
			while(!q.empty()){
				q.pop();
			}
		}
		else{
			p.push(q.front());
			q.pop();
		}
	}
	q.swap(p);
	while(!p.empty()){
		p.pop();
	}
	q.push(x);
}
void he(){
	while(!q.empty()){
		ans[q.front()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cow(a[j]);
		}
		he();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
