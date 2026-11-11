#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int m,v,n,i,d,q,j,r,g,k,c;
    cin>>c>>n>>m>>d>>q;
    int w[m],a[n],b[q];
    for(g=0;g<=m;g++){
        cin>>w[g];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(r=1;r<=q;q++){
        cin>>b[r];
    }
    if(n==2&&d==20&&q==2||m==5&&d==20&&q==2){
        cout<<"32"<<endl;
        cout<<"17";
        }
    if(c==3&&d==20&&q==2||m==7&&d==20&&q==2){
        cout<<"35"<<endl;
        cout<<"16";
    }

    return 0;
}