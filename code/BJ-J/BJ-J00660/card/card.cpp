#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],c[500050];
void ccp(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int w=1;
    for(int i=1;i<=n;i++){
        w=1;
        for(int o=i;o<=n;o++){
            for(int p=1;p<w;p++){
                if(b[p]==a[o]){
                    w=p;
                    break;
                }
            }
            b[w++]=a[o];
        }
        for(int o=1;o<w;o++){
            c[b[o]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ccp();
    return 0;
}