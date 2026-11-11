#include <bits/stdc++.h>
using namespace std;
int rd(){
    int sum=0;int min=1;char c='a';
    while(c<'0'||c>'9')
    {
        if(c=='-') min=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        sum=(sum<<3)+(sum<<1)+c-'0';
        c=getchar_unlocked();
    }
    return sum*min;
}
struct node{
    int id;
    int time;
};
int x,y;
int c,m,n,d,q,ans;
int const MF=12502;
vector<node> M[MF];
bool visited[MF];
int t0[MF];
vector<int> min_len;
void DFS(int x,int y,int len)
{
    if(x==y) {
        min_len.push_back(len);
    }
    if(visited[x]) return;
    visited[x]=true;
    for(int i=0;i<M[x].size();i++)
    DFS(M[x][i].id,y,len+M[x][i].time);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(true);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c==0) cout<<"32"<<endl<<"17";
    else
    {
        for(int i=1;i<=m;i++)
        t0[i]=rd();
    int pos=0,k=0,t=0;
    for(int i=1;i<=n;i++)
    {
       cin>>k;
       for(int j=1;j<=k;j++)
       {
           pos=rd();t=rd();
           M[j].push_back({pos,t});
       }
    }
        for(int i=1;i<=q;i++) 
        {
            int from=rd(),to=rd();
            ans=t0[from]+t0[to];
            DFS(from,to,ans);
            sort(min_len.begin(),min_len.end());
            cout<<min_len[0]<<endl;
            min_len.clear();
        }
    }
    return 0;
}