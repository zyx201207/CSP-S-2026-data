#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],cnt[500005];
	queue<int>q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[j];
			bool z=1;
			queue<int>w;
			while(!q.empty()){
				int h=q.front();
				q.pop();
				if(h==x)z=0;
				if(z){
					w.push(h);
				}
			}
		}
		while(!q.empty()){
			int h1=q.front();
			q.pop();
			cnt[h1]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
	}
}
