#include<bits/stdc++.h>
using namespace std;
int n,m,p,ans[300005],b[300005],pos;
bool vis[300005];
queue<int> a;
void game(){
	int s=a.size();
	pos=1;
	for(int k=1;k<=s;k++){
		int t=a.front();
		b[pos]=t;
		if(vis[t]){
			pos--;
			while(b[pos]!=t){
				vis[b[pos]]=0;
				pos--;
			}
		}
		vis[t]=1;
		pos++;
		if(k!=1){
			a.push(t);
		}
		a.pop();
	}
	for(int j=1;j<pos;j++){
		ans[b[j]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p;
		a.push(p);
	}
	for(int i=1;i<=n;i++){
		game();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}
