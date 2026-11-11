#include <bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],s[M];
bool t[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	for(int x=1;x<=n;x++){
		stack<int>q;
		for(int y=x;y<=n;y++){
			if(t[a[y]]==0){
				q.push(a[y]);
				t[a[y]]=1;
			}else{
				while(q.top()!=a[y]){
					t[q.top()]=0;
					q.pop();
				}
			}
		}
		while(q.size()){
			s[q.top()]++;
			t[q.top()]=0;
			q.pop();
		}
	}
	for(int x=1;x<=m;x++){
		cout<<s[x]<<' ';
	}
	return 0;
}
