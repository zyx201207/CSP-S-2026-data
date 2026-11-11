#include <bits/stdc++.h>
using namespace std;

const int mx=5*1e5+5,ms=3*1e5+5;
int nrr[mx],re[ms],mrr[mx],br[ms];

bool un(int x){
    if(re[x]==0){re[x]++;return true;}
    else return false;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nrr[i];
    }
    int j=0,di=0;
    for(int i=0;i<n;i++){
        if(un(nrr[i])){mrr[j]=nrr[i];br[mrr[i]]++;j++;}
        else {
            di=br[nrr[i]];
            j=br[nrr[i]];
            for(;di<i;di++){mrr[di]=0;re[mrr[di]]=0;}
            mrr[j]=nrr[i];
           // br[mrr[i]]=j;
            j++;
        }
    }
    for(int i=0;i<m-1;i++)cout<<br[i]+1<<' ';
    cout<<br[m-1]+1<<'\n';

    return 0;
}
