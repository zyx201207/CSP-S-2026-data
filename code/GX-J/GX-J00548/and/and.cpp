#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int nn[100];
    int nm[100];
    int n;
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nn[i];
    }
    for(int i=0;i<n;i++){
        nm[i]==nn[i] and nn[i+1];
    }
    int mj=nm[0];
    for(int=0;i<n;i++){
        if(mj<nm[i])mj=nm[i];
    }
    cout<<mj;
    return 0;
}
