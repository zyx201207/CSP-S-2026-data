#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int arr[N];
int ans[M];
void game(int now){
	set<int> s;
	stack<int> q;
	for(int i=now;i<=n;i++){
		if(!s.count(arr[i])){
			q.push(arr[i]);
			s.insert(arr[i]);
		}else{
			while(q.top()!=arr[i]){
				s.erase(q.top());
				q.pop();
			}
		}
	}
	while(!q.empty()){
		ans[q.top()]++;
		q.pop();
	} 
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 

