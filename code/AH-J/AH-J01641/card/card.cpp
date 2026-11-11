#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
queue<int> q;
bool check(int x){
	queue<int> qq=q;
	for(int i=1;i<=q.size();i++){
		if(qq.front()==x) return false;
		qq.pop();
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int js=0;
	while(js<n){
		js++;
		while(!q.empty()){
			b[q.front()]++;  
			q.pop();
		}
		for(int i=js;i<=n;i++){
			if(check(a[i])==true){
				q.push(a[i]);
			}
			else{
				while(!q.empty()) q.pop();
				q.push(a[i]);
			}
		}
	}
	while(!q.empty()){
		b[q.front()]++;
		q.pop();
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
} 
