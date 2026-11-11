#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int cnt[N+1];
struct card{
    int num;
    bool use;
};
card a[N+1];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].use=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            a[j].use=true;
            for(int x=j-1;x>=i;x--){
                if(a[x].num==a[j].num&&a[x].use){
                    for(int de=x;de<j;de++){
                        a[de].use=false;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int x=i;x<=n;x++){
                if(a[x].use)cnt[a[x].num]++;
                a[x].use=false;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
