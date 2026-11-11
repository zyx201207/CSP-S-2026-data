#include<queue>
#include<iostream>
using namespace std;
const int N=2e5+5;
int n,m;
queue<int> q;
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	for(int i=30;i>=0;i--){
		int mask=1<<i;
		int cnt=0;
		queue<int> a,b;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			if(x&mask){
				a.push(x);
				cnt++;
			}else b.push(x);
		}
		if(cnt>=m){
			ans+=mask;
			while(!a.empty()){
				q.push(a.front());
				a.pop();
			}
			while(!b.empty())b.pop();
		}else{
			while(!b.empty()){
				q.push(b.front());
				b.pop();
			}
			while(!a.empty()){
				q.push(a.front());
				a.pop();
			}
		}
	}
	cout<<ans;
}
