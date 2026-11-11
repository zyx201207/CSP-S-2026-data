#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string smv1,smv1w,smv2,smv2w;
    cin>>smv1>>smv1w>>smv2>>smv2w;
    if(smv1==smv2)
        if(smv1w.substr(0,2)==smv2w.substr(0,2))
            if(smv1w[2]<='C'&&smv2w[2]<='C'||smv1w[2]>='D'&&smv2w[2]>='D'){
                bool o=(smv1w[2]!='A');
                char m=(smv1w[2]!='A' ? smv1w[2] : smv2w[2]);
                if(o&&char(m+1)==smv2w[2]||!o&&char(m+1)==smv1w[2]||o&&char(m-1)==smv2w[2]||!o&&char(m-1)==smv1w[2])cout<<"1111";
                else cout<<"1110";
            }else cout<<"1100";
        else cout<<"1000";
    else cout<<"0000";

    return 0;
}
