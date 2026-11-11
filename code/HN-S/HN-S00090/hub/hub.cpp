#include<bits/stdc++.h>
using namespace std;
const int N=5e7;
int c,T;
int n,k;
struct side{
    int from;
    int endd;
    int next;
    int vea;
}mp[N];
int cnta;
int head[N];
void add(int from,int endd){
    cnta++;
    mp[cnta].endd=endd;
    mp[cnta].from=from;
    mp[cnta].next=head[from];
    head[from]=cnta;
}
struct e{
    int num;
    int deep;
};
queue<e> p;
bool book[N];
int solve(int from){
    e pi;
    pi.num=from;
    pi.deep=0;
    book[pi.num]=1;
    p.push(pi);
    int maxn=0;
    int maxnn=0;
    int cnt=1;
    while(!p.empty()){
        pi=p.front();
        p.pop();
        book[pi.num]=1;
        maxnn=maxn;
        maxn=pi.deep;
        cnt++;
        if(cnt==k)break;
        for(int i=head[pi.num];i;i=mp[i].next){
            int v=mp[i].endd;
            if(book[v])continue;
            e pp;
            pp.num=v;
            pp.deep=pi.deep+1;
            p.push(pp);
        }
    }
    return maxn+maxnn;
}
void clean(){
	while(!p.empty())p.pop();
	for(int i=1;i<=n;i++)book[i]=0;
}
int main(){
	// 注意修改宏
	// 注意加freopen
		freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        for(int i=1;i<=n;i++){
			clean();
            cout<<solve(i);
        }
    }
    return 0;
}
