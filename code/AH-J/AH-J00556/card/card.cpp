#include <iostream>
#include <stack>
#include <map>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int n,m,dis[500005],a[500005],mm[300005];
stack<int> s;
void pl(int x){
	for(int i=x;i<=n;i++){
		if(mm[a[i]]!=0){
			while(!s.empty()){
				int h=s.top();
				s.pop();
				mm[h]--;
				if(h==a[i]) break;
			}
		}
		mm[a[i]]++;
		s.push(a[i]);
	}
	while(!s.empty()){
		int h=s.top();
		s.pop();
		dis[h]++;
		mm[h]--;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pl(i);
	}
	for(int i=1;i<=m;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
