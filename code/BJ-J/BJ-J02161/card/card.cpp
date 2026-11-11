#include<bits/stdc++.h>
using namespace std;
const int Maxn1=5e5+5,Maxn2=3e5+5;
int n,m,a[Maxn1],box[Maxn2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		queue<int> q;
		for(int j=i;j<=n;j++){
			for(int v:q){
				if(v==a[j]) {q.erase();break;}
			}
			q.push(a[j]);
		}
		for(int v:q){
			box[v]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<box[i]<<' ';
	}
	return 0;
}
