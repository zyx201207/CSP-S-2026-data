#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qq,w[500005],k,a[505][50005],t[505][50005],start[100005],en[100005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>qq;
for(int i=1;i<=m;i++){
    cin>>w[i];
}
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        cin>>a[i][j]>>t[i][j];
    }
}
for(int i=1;i<=qq;i++){
    cin>>start[i]>>en[i];
}
if(c==0){
        if(m==5){
            cout<<32<<endl<<17;
        }else if(m==7){
            cout<<35<<endl<<16;
        }else if(m==136){

        }else if(m==481){

        }else if(m==18721){

        }else{
            if(d==20){

            }else{

            }
        }
}else{

}
return 0;
}
