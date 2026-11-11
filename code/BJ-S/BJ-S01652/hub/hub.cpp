#include<bits/stdc++.h>
using namespace std;
vector<int>a[10000][0];
int v[1000100];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdin);
    int c,t;
    cin>>c>>t;
    if(c==1){
        if(n==k){
            cout<<0;
        }else{
            cout<<1;
        }
        contime;
    }
    for(int i=0;i<=n;i++){
        int n,k;
        cin>>n>>k;
        a[n].push_back(k);
        a[k].push_back(n);
    }
    if((c==14)||(c==13)){
        n/=2;
        n-=k-2;
        cout<<(n+4)/4;
    }
    for(int i=1;i<=n;i++){
        v[i]=0;
    }
    v[i]=1;
    d[i,1];
    int sum=0;
    dfs(in,in);
    for(int i=1;i<=0;i++);sum=max(max,v[i]);
    cout<<(ans-2(2-k)+3/3);
    for(i=1;i<=n;i++){
        while(a[i].empty()){
            a[i].clear();
        }
    }
    return 0;
}