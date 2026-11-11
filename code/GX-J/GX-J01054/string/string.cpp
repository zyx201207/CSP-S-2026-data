#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;
    cin>>n;
    int x[n+1]={0};
    char y[n+1]={0};
    string lev;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        for(int j=1;j<=x[i];j++){
            lev+=y[i];
        }
    }int prx=1,xlg=x[1];
    for(int i=1;i<lev.size();i++){
        if(lev[i]==lev[0]){
            prx++;
        }
        if(y[i]==y[i-1] and y[i]==y[1]){
            xlg+=x[i];
        }
    }
    if(prx==lev.size()){
        cout<<0;
    }
    else{cout<<xlg;}
    return 0;
}
