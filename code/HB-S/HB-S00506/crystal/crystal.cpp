#include <bits/stdc++.h>
using namespace std;
int b[100005],c[100005],g=0,v=0,p=0,x;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    v=n/2;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(b[i]-b[j]<m){
                g++;
                //cout<<b[i]<<" "<<b[j]<<endl;
            }
        }
    }

    cout<<g/b[n];

    return 0;
}
