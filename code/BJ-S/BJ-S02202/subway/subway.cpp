#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t;
vector<int> xl[125501];
int a[125501];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>y;
        for(int i=1;i<=y;){
            cin>>x;
            cin>>z;
            xl[x].push_back(i);
            i+=2;
        }
    }
    while(t--){
        int l,r,f=0;
        cin>>l>>r;
        for(int i=0;i<xl[l].size();i++){
            for(int j=0;i<xl[r].size();j++){
                if(xl[l][i]==xl[r][j]){
                    cout<<2*z+a[l]+a[r]<<endl;
                    f=1;
                }
            }
        }
        if(f==0){
            cout<<4*z+a[l]+a[r]<<endl;
        }
    }
    return 0;
}
