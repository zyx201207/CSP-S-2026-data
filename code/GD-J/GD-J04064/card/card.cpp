#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[500005],b[500005],f[500005],x;
queue<int>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int y=i;y<=n;y++){
			x=a[y];
			q.push(x);
			b[x]++;
		}
		while(!q.empty()){
			k=q.front();
			q.pop();
			while(b[k]>1){
				x=q.front();
				b[x]--;
				if(b[k]>1){
					q.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				f[j]++;
				b[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
