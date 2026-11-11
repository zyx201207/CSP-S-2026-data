#include <bits/stdc++.h>
using namespace std;
int n;
struct mn{
    long long k;
    char p;
}w[200005];
long long ans,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out" ,"w",stdout);
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>w[x].k>>w[x].p;
    }
    bool pd1=true,pd2=true;
    for(int x=1;x<=n-1;x++){
        if(w[x].k!=w[x+1].k && pd1){
            pd1=false;
        }
        if(w[x].p!=w[x+1].p && pd2){
            pd2=false;
        }
        if(!pd2 && !pd1){
            break;
        }
    }
    if(pd2){
        cout<<0;
    }
    else if(pd1){
        for(int x=1;x<=n/2;x++){
            if(w[x].p!=w[n+1-x].p){
                ans+=w[x].k;
            }
        }
        cout<<ans;
    }
    if(!pd1 && !pd2){
            int b=n;
            for(int x=1;;){
                if(x==b){
                    cout<<ans;
                    break;
                }
                if(w[x].p!=w[b].p){
                    if(w[x].k>w[b].k){
                        ans+=w[b].k;
                        w[x].k-=w[b].k;
                        b--;
                    }
                    else{
                        ans+=w[x].k;
                        w[b].k-=w[x].k;
                        x++;
                    }
                }

            }
    }
    return 0;
}

