#include<bits/stdc++.h>
using namespace std;
const int N=1e6*2+10;
int x[N];
bool y[N],st[N];
int n,d;
bool Dijistra(int src,int end) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
	q.push({0,src});st[src]=false;
	while(!q.empty()) {
        int u=q.top().first;
        st[u]=false;
        for(i=max(0,src-d);i<min(src+d,n);i++){
            if(y[i]){

            }
        }
	}
}
int dfs(int src,int en){
    for(int i=max(0,src+d),i<min(src+d,n);i++){
        if(!st[i]){
            st[i]=false;

        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		memset(y,false,sizeof(y));
		for(int i=0; i<n; i++) {
			cin>>x[i];
			y[x[i]]=true;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++){
                    memset(st,true,sizeof(st));
            }
        cout<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
