#include<bits/stdc++.h>

using namespace std;

const int MAXN=5*1e5+5;

int n,m;
int a[MAXN];

struct card_t{
    bool in;
    int num;
};

int cnt[300005];

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        int r=0;
        int card[MAXN]={-1};
        card_t t[300005];
        for(int j=1;j<=m;j++){
            t[j].in=0;
            t[j].num=0;
        }
        for(int j=i;j<=n;j++){
            card[++r]=a[j];
            if(t[a[j]].in){
                for(int k=t[a[j]].num+1;k<r;k++){
                    t[a[k]].in=false;
                }
                r=t[a[j]].num;
                
            }
            t[a[j]].in=true;
            t[a[j]].num=r;
        }
        for(int j=1;j<=r;j++){
            cnt[card[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    return 0;
}