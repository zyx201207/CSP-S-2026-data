#include<bits/stdc++.h>
using namespace std;

const int N=5e3 +9;
int n,m,a[N],b[N],d[N];
stack<int>s;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int j=1;j<=n;++j){
        for(int i=1;i<=m;++i){
            d[i]=0;
        }
        for(int i=j;i<=n;++i){
            if(d[a[i]]){
                while(!s.empty()){
                    int x=s.top();
                    d[x]=0;
                    if(x==a[i]){
                        s.pop();
                        break;
                    }
                    s.pop();
                }
            }
            s.push(a[i]);
            d[a[i]]=1;
        }
        while(!s.empty()){
            int x=s.top();
            b[x]++;
            s.pop();
        }
    }

    for(int i=1;i<=m;++i){
        cout<<b[i]<<" ";
    }

    return 0;
}
