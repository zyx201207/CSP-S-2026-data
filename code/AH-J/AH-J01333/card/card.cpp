#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	map<int,int> k;
	queue<int> b,c;
	cin>>n>>m;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			cin>>a;
			k[a]++;
			b.push(a);
			if(k[a]>1){
				c.push(b.front());
				b.pop();
				while(b.front()!=a){
					c.push(b.front());
					b.pop();
				}c.push(b.front());
				b.pop();
			}
		}
	}

	while(!b.empty()){
		cout<<b.front()<<' ';
		b.pop();
	}
	return 0;
}//不给我奖的是GAY
