#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5,M=3*1e5+5;
int a[N],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	deque<int> que;
	for(int i=0;i!=n;++i){
		cin>>a[i];
	}
	for(int i=0;i!=n;++i){
		que.clear();
		for(int j=i;j!=n;++j){
			if(find(que.begin(),que.end(),a[j])!=que.end()){
				while(*que.end()!=a[j]){
					que.pop_back();
				}
			}
			que.push_back(a[j]);
		}
		for(auto i:que){
			++cnt[i];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<cnt[i]<<' ';
	}
}
