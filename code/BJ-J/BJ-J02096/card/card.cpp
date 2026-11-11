#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],b[M]={0},ma=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }for(int i=1;i<=n;i++){
        int st[N],top=i-1,cnt=1;
        bool vis[N];
        for(int j=i;j<=n;j++){
            if(!vis[st[top]]){
                top++;
                st[top]=a[j];
                vis[st[top]]=true;
            }else{
                while(st[top]!=a[j]&&top>=i){
                    vis[st[top]]=false;
                    top--;
                }
            }
        }for(int j=i;j<=top;j--){
            b[st[j]]++;
        }
    }for(int i=1;i<=ma;i++){
        if(b[i])cout<<b[i]<<' ';
    }

    return 0;
}

