#include<bits/stdc++.h>
using namespace std;
int n,gs,cs=0,l=0;
string zf,hw="";
void xg(string shu){
    l=shu.size();
    for(int i=0;i<l/2;i++){
        if(shu[i]!=shu[l-i-1]){
            cs++;
            shu[l-i-1]=shu[i];
        }
    }
    return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>gs>>zf;
        for(int j=0;j<gs;j++){
            hw+=zf;
        }
    }
    if(n==1){
        cs=0;
    }
    else if(n>=2){
        xg(hw);
    }
    cout<<cs;
    return 0;
}

