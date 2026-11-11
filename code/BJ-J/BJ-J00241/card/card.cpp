#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500010];
int b[500010];
int t[300010];

int pc(int x, int y){
    for(int i=0;i<=x;i++){
        if(b[i]==a[y]){
            for(int j=i;j<=x;j++){
                b[j]=0;
            }
            b[i]=a[y];
            return i+1;
        }
    }
    b[x]=a[y];
    return x+1;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=0;j<n;j++){
            b[j] = 0;
        }
        for(int j=i;j<n;j++){
            x = pc(x, j);
        }
        for(int j=0;j<=x;j++){
            t[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
