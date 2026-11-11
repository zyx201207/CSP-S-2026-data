#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
vector<int> a(N);
bool vis[N];
stack<int> s;
vector<int> vals[N];//每个a[i]的位置
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vals[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!s.empty()){
				while(s.top()!=a[j]) s.pop();
				s.pop();
			}
 			if(!vis[j]) s.push(a[j]);
		}
	}
	
	return 0;
} 
