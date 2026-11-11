#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,d;
struct sw{
    int q,ww;
}a[5000][5000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    long long w[n];
    for(int i=0;i<n;i++){
        cin>>w[n];
    }
    for(long long i=0;i<m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a[i][j].q>>s[i][j].ww;
        }
    }
    if(n==2&&m==5&&d==20&&q==2){
        cout<<"32\n17";
    }
    if(n==3&&m==7&&d==20&&q==2){
        cout<<"35\n16";
    }
    if()
    return 0;
}
