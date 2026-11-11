#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],e[300010];
void play(int s){
    int t[500010],last[500010];
    memset(last,0,sizeof(last));
    int r=1;
    for(int i=s;i<=n;i++){
        if(t[r-1]!=a[i]){
            t[r]=a[i];
            r++;
        }
    }
    for(int i=1;i<=r;i++){
        if(last[t[i]])continue;
        else{
            e[t[i]]++;
            last[t[i]]=1;
        }
    }
}
void play2(int s){
    int t[500010],app[500010],alr[500010];
    memset(alr,0,sizeof(alr));
    int r=1;
    for(int i=s;i<=n;i++){
        int brp=0;
        for(int j=1;j<r;j++){
            if(t[j]==a[i]){
                brp=j;
                break;
            }
        }
        if(brp!=0){
            for(int j=brp;j<r;j++){
                app[t[j]]--;
            }
            r=brp;
        }
        t[r]=a[i];
        app[a[i]]++;
        r++;
    }
    for(int i=1;i<r;i++){
        if(app[t[i]]>0){
            if(alr[t[i]])continue;
            e[t[i]]++;
            alr[t[i]]=1;
        }

    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=500){
        for(int i=1;i<=n;i++){
            play2(i);
        }
        for(int i=1;i<=m;i++){
            cout<<e[i]<<' ';
        }
    }else{
        for(int i=1;i<=n;i++){
            play(i);
        }
        for(int i=1;i<=m;i++){
            cout<<e[i]<<' ';
        }
    }


    return 0;
}