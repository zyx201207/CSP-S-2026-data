#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],v[N],vis[N],n,m;
void find(int x){
	if(x>n) return;
	//cout<<x;
	if(v[a[x]]==0){
		v[a[x]]=x;
		vis[a[x]]++;
		find(x+1);
	}
	else{
		vis[a[x]]++;
		find(v[a[x]]+1);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		find(i);
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
}
