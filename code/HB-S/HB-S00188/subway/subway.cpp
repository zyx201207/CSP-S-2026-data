#include<bits/stdc++.h>
using namespace std;
int a[500005],pl[500005][2],t[505][500005];
int c,n,m,d,p;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int i=1;i<=x;i++){
            int o,q;
            cin>>o>>q;
            t[i][o]=q;
        }
    }
    for(int i=1;i<=p;i++){
        cin>>pl[i][0]>>pl[i][1];
    }
    int mn=INT_MAX;
    for(int k=1;k<=p;k++){
        int tm=0;
        tm+=a[pl[k][0]]+a[pl[k][1]];
        for(int i=1;i<=n;i++){
            bool f=false;
            for(int j=1;j<=m;j++){
                if(t[i][pl[k][0]]!=0){
                    tm+=t[i][pl[k][0]];
                    f=true;
                }
                if(f){
                    tm+=t[i][pl[k][0]];
                }
                if(t[i][pl[k][1]]!=0){
                    tm+=t[i][pl[k][0]];
                    f=false;
                }
            }
        }
        mn=min(mn,tm);
    }
    cout<<mn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
