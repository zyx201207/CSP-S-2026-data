#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],cnt[N];
bool fin(stack<int>w,int x){
	while(!w.empty()){
		if(w.top()==x){
			return true;
		}else{
			w.pop();
		}
	}
	return false;
}
void lun(int x){
	stack<int>q;
	for(int i=x;i<=n;i++){
		if(fin(q,a[i])){
			while(q.top()!=a[i]){
				q.pop();
			}
		}else{
			q.push(a[i]);
		}
	}
	while(!q.empty()){
		cnt[q.top()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		lun(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
