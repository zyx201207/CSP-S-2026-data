#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    int p[100005]={},z[100005]={},t[100005]={0};
    cin>>n>>m;
    int x,top;
    int mj[100005]={};
    for(int i=1;i<=n;i++){
        cin>>x;
        p[i]=x;
    }int y;

    for(int k=1;k<=n;k++){
        t[100005]={0};
        z[100005]={0};
        for(int i=k;i<=n;i++){
            y=p[i];
            z[top]=y;
            t[y]++;
            if(t[y]==2){
                for(int j=top-1;j>=1;j--){
                    x=z[j];
                    t[z[j]]=0;
                    z[j]=0;
                    top--;
                    if(x==y){
                        break;
                    }
                }
            }
            top++;
        }
        for(int i=1;i<=m;i++){
            mj[i]+=t[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mj[i]<<" ";
    }

    return 0;
}
