#include<bits/stdc++.h>
using namespace std;
int st[500005];
int card[500005];
int ans[300005];
int n,m;
void popst(int x){
    int flag=0;
    for(int i=0;i<n;i++){
        if(st[i]==0)break;
        if(flag==1||st[i]==x){
            st[i]=0;
            flag=1;
        }
    }
    for(int i=0;i<n;i++){
        if(st[i]==0){
            st[i]=x;
            break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    int r=0;
    for(int t=0;t<n;t++){
        for(int i=r;i<n;i++){
            popst(card[i]);
        }
        for(int i=0;i<n;i++){
            if(st[i]==0)break;
            ans[st[i]]++;
        }
        for(int i=0;i<n;i++){
            if(st[i]==0)break;
            st[i]=0;
        }
        r++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
