#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int ans[300001];
	int a[500001],b[300001];
	cin >>n>>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		int op=i;
		queue<int> q;
		queue<int> q1;
		q1.push(a[i]);
		while(q1.empty()){
			int t = q1.top();
			q1.pop();
			if(b[t]!=1){
				q.clean();
				q.push(t);
			}
			else{
				q.push(t);
			}
			op++;
			q1.push(a[op]);
		}
		for(auto k : q;;)ans[k]++;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i];
	return 0;
}
