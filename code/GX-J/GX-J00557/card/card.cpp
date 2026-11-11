#include<bits/stdc++.h>
using namespace std;
int n,m,vis[300001],a[500001];
int tp[300001];
int s[500001],top=0;
void Card_(int x){
    memset(tp,0,sizeof(tp));
    for(int i=x;i<=n;i++){
        if(!tp[a[i]])tp[a[i]]=1,s[++top]=a[i];
        else{
            while(s[top]!=a[i])tp[s[top]]=0,top--;
            top--,s[++top]=a[i];
        }
    }while(top){
        vis[s[top--]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        Card_(i);
    }for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
}
