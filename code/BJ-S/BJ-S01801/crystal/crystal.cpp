#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,r=0;
    cin>>n>>m;
    int q[n]={0};
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    sort(q,q+n);
    int x=0;
    x=q[n/2+1];
    int w[n]={0};
    for(int i=0;i<n;i++){
        if(q[i]==x){
            r++;
        }
    }
    for(int i=0;i<n;i++){
        if(q[i]<n){
            w[i]=n-q[i];
        }
        else{
            w[i]=q[i]-n;
        }
    }
    while(m>0){
        long long e=1e19;
        for(int i=0;i<n;i++){
            if(w[i]!=0){
                if(w[i]<e){
                    e=w[i];
                    w[i]=0;
                }
            }
        }
        m-=e;
        if(m>0){
            r+=1;
        }
    }
    cout<<r;
    return 0;
}
