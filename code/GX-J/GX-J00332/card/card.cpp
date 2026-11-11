#include<bits/stdc++.h>
using namespace std;
int l[500005];
int have[300005];
int p[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&l[i]);
        p[i]=1;
        if(i>0)p[i]+=p[i-1];
    }
    for(int i = 0;i<n;i++){
        have[l[i]]=-1;
    }
    for(int i = 0;i<n;i++){
        if(have[l[i]]!=-1){
            for(int j = have[l[i]]+1;j<i;j++)p[j]-=p[have[l[i]]];
        }
        have[l[i]]=i;
    }
    for(int i = 0;i<n;i++){
        have[l[i]]=max(have[l[i]],p[i]);
    }
    for(int i = 1;i<=m;i++){
        cout<<have[i]<<' ';
    }
}
