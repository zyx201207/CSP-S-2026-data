#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],ans[300005];
int p[500005],l,r=-1;

int fd(int num){
    for(int i=l;i<=r;i++)
        if(p[i]==num)
            return i;
    return -1;
}

void place(int num){
    int ps=fd(num);
    if(ps==-1){
        p[++r]=num;
    }
    else{
        r=ps-1;
        p[++r]=num;
    }
}

void clr(){
    for(int i=l;i<=r;i++)
        p[i]=0;
    l=0;r=-1;
}

void st(){
    for(int i=l;i<=r;i++){
        ans[p[i]]++;
    }
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++){
        clr();
        for(int j=i;j<n;j++){
            place(a[j]);
        }
        st();
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';

    return 0;
}
