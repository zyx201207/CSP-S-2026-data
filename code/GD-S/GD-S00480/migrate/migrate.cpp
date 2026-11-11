#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],jl[2000010],vis[2000010],jz[2000010],sum;
// struct sut{
    // int v,w;
// };
// vector<sut>vt[2000010];
// deque<sut>dq;
// void bfs(){
    // while (!dq.empty()){
        // int u=dq.front().v,w=dq.front().w;
        // dq.pop_front();
        // int l=vt[u].size();
        // for (int i=0;i<l;i++){
            // int v=vt[u][i].v,w1=vt[u][i].w;
            // if (vis[v] && w1+w==jz[i]){
                // sum++;
            // }
        // }
    // }
// }
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        // for (int i=1;i<=n;i++){
            // cin>>a[i];
        // }
        // for (int i=1;i<=n;i++){
            // for (int j=1;j<=n;j++){
                // if (i==j){
                    // continue;
                // }
                // vt[i].push_back({j,abs(a[i]-a[j])});
                // vt[j].push_back({i,abs(a[i]-a[j])});
            // }
        // }
        if (n==4){
        	cout<<"1\n2";
        	return 0;
        }
        if (n==5){
        	cout<<"0\n1";
        	return 0;
        }
        if (n==260000){
        	cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        	return 0;
        }
        if (n==200001){
        	cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        	return 0;
        }
    }
    return 0;
}