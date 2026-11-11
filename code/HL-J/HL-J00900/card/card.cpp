#include<bits/stdc++.h>
using namespace std;
int a[111111],b[111111],x[111111],ans[111111];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin>>x[i];
            int r=x[i];
            if(b[x[i]]==0){
                continue;
            }
            else{
                i=b[x[i]];
                x[i+1]=r;
            }
        }
        for(int i=0;i<111111;i++){
            ans[i]=x[i];
        }

    }

}









































































































































































