#include<bits/stdc++.h>
using namespace std;
int p[1000000]={},d[100000]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,c,m=0,ans[100000]={};
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c;
        p[i]=c;
        d[i]=c;
    }
    for(int i=0;i<a;i++){
        for(int u=i+1;u<a;u++){
            if(p[i]==p[u]){
                m=u;break;
            }
            else{

            }
        }
        if(m!=0)break;
        else{
            continue;
        }
    }
    for(int i=0;i<m;i++){
        p[i]=0;
        d[m-i]=0;
    }
    for(int i=0;i<a;i++){
        for(int u=1;u<=b;u++){
            if(p[i]==u or d[i]==u){
                ans[u]=i;
            }
        }
    }
    for(int i=1;i<=b;i++){
       cout<<ans[i]+1<<" ";
    }
    return 0;
}
