#include<iostream>
using namespace std;
int c,n,m,d,q,k;
int w[100005];   //kou->ting       
int a[105][100005];   //tujingzhan
int t[100005];   //ting->tai
int r[100005][2];//jihua
int find(int a,int b){
    if(a==b){
        return 1;
    }
    for(int i=1;i<=100005;i++){
        for(int j=1;j<=100005;j++){
            )
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];             
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i]>>t[i];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i][0]>>r[i][1];
    }
    return 0;
}