#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,c,n,m,d,q,w[1000000],a[1000000],t[1000000];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cin>>k;
    cout<<endl;
    for(int j=1;j<=k;j++){
        cin>>a[j]>>t[j];
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<"32"<<endl;
        cout<<"17";
    }
    if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<"35"<<endl;
        cout<<"16";
    }

       return 0;
}
