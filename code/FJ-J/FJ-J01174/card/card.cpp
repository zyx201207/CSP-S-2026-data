#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],t[300010],tt[300010];
stack<int> q;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int ii=1;ii<=n;ii++){
		for(int i=ii;i<=n;i++){
			if(t[a[i]]){
				while(q.top()!=a[i]){
					int mm=q.top();
					t[mm]=0;
					q.pop();
				}
				int mm=q.top();
				t[mm]=0;
				q.pop();
			}
			t[a[i]]=1;
			q.push(a[i]);
		}
		while(!q.empty()){
			int mm=q.top();
			tt[mm]++;
			t[mm]=0;
			q.pop(); 
		}
	}
	for(int i=1;i<=m;i++) cout<<tt[i]<<" ";
}
