#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
map<int,int> p;
map<int,int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p.find(a[i])==p.end()){
			p[a[i]]=i;
		}
		else{
			b[i]--;
			b[p[a[i]]-1]++;
			p[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
	}
	for(int i=n;i>=1;i--){
		if(q.find(a[i])==q.end()){
			q[a[i]]=i-b[i];
		}
	}
	for(auto i:q){
		cout<<i.second<<" ";
	}
	return 0;
}
