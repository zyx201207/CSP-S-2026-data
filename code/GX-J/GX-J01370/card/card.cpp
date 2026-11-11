#include<bits/stdc++.h>
using namespace std;
stack<int>q;
int main(){
    freopen("card.in","r",stdin);
    reopen("card","w",stdout);
    int f=0,n,m,s,a[10001]={},b[10001]={},c[10001]={},d[1001]={},e[1001]={},k=0;
    cin>>n>>m;
    int w=1;
    cin>>b[1];
    q.push(b[1]);
        d[b[1]]++;
        e[w]=b[1];
        w++;
    for(int i=2;i<=n;i++){
        cin>>s;
        if(d[s]==0&&w<=m){
            d[s]++;
            e[w]=s;
            w++;
        }
        for(int j=i;j>0;j--){
                cout<<b[j]<<" ";
            if(b[j]==s){
                k=1;
                for(int p=1;p<=i-j;p++){
                    cout<<q.top();
                    q.pop();
                }
                q.push(s);
            }
        }
        if(k==0){
            b[i]=s;
        }
        f=0;
        memset(a,0,10001);
            while(!q.empty()){
                f++;
                a[f]=q.top();
                cout<<q.top();
                c[q.top()]++;
                q.pop();
            }
            memset(b,0,10001);
            for(int u=1;u<=f-1;u++){
                b[u]==a[f-u+1];
                q.push(a[f-u+1]);
            }
    }
    for(int v=1;v<=w-1;v++){
        cout<<c[e[v]];
    }
    return 0;
}
