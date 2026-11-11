#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const ll MAX=100000001;
int c;
int v(int p){
    for(int i=0;i<n;i++){//同条线路
        for(int j=0;j<n;j++){
            if(a[i][j]==x){
                for(int i1=0;i1<n;i++){
                    for(int j1=0;j1<n;j++){
                        if(a[i1][j1]==y){
                            c=
                        }

                    }
                }
            }

        }
    }
    for(int i=0;i<n;i++){//异条线路
        for(int j=0;i<n;j++){

        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q,x[MAX],y[MAX];
    cin>>c>>n>>m>>d>>q;
    int w[m],k[n],a[MAX][MAX],t[MAX][MAX];
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<1;i++){
        v(i);
    }

    return 0;
}
