#include<bits/stdc++.h>
using namespace std;
int a[500005],b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	queue<int>q,q1,e;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)e.push(a[j]);
		while(!e.empty()){
			bool d=0;
			q1=q;
			q.push(e.front());
			while(!q1.empty()){
				if(q1.front()==e.front()){
					d=1;
					break;
				}
				q1.pop();
			}
			if(d){
				while(q.front()!=e.front()){
					e.push(q.front());
					q.pop();
				}
				q.pop();
			}
			e.pop();
		}
		b[q.back()]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
