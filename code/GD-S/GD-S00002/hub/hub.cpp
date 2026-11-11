#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
long long fa[MAXN];
int find(int x){
	if(fa[x] != x){
		fa[x] = find(x);
	}
	return fa[x];
}
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x != y){
		fa[y] = find(x);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t; cin>>c>>t;
	int op,x,y;
	for(int i=1;i<t;i++){
		fa[i] = 1;
	}
	while(t--){
		cin>>x>>y;
		if(op==1){
			unite(x,y);
		}
		if(find(x)==find(y)){
			cout<<1<<endl;
			break;
		}else{
			cout<<2<<endl;
			break;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
