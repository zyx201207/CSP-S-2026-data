#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,w;
}box[300005];
int n,m,a,b[300005];
queue<int>q,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		q.push(a);
		p.push(a);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p.size();j++){
			q.push(p.front());
			p.push(p.front());
			p.pop();
			box[j].s=0;
			box[j].w=0;
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				q.push(q.front());
				q.pop();
			}
			if(box[q.front()].s==1){
				for(int l=1;l<=box[q.front()].w-1;l++){
					q.push(q.front());
					q.pop();
				}
				for(int l=box[q.front()].w;l<=j;l++){
					box[q.front()].s--;
					q.pop();
				}
				
			}
			else{
				box[q.front()].s++;
				box[q.front()].w=1;
			}
		}
		for(int j=1;j<=m;j++){
			b[j]+=box[j].s;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	cout<<"\n";
	return 0;
} 
