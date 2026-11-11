#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],cnt[M];
vector<int>b[M];

void f(int round){
    int nw;
    bool er=0;
    for(int i=round;i<=n;){
        er=0;
        nw=a[i];
        for(int j:b[nw]){
            if(j>i){
                i=j;
                er=1;
                break;
            }
        }
        if(er==0){
            cnt[nw]++;
            i++;
        }
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool spA=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])spA=0;
        b[a[i]].push_back(i);
    }
    if(spA==true){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])cnt[a[i]]=i;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            f(i);
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}