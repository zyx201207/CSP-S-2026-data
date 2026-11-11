#include<bits/stdc++.h>
using namespace std;
int n[15],m[15],d[15],a[15],b[15],p[15],o[15],t[15];
char s,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<2;i++){
        cin>>n[i];
    }
    for(int y=1;y<2;y++){
        cin>>b[y]>>p[y]>>s;
    }
    for(int j=1;j<2;j++){
        cin>>d[j];
    }
    for(int u=1;u<2;u++){
        cin>>o[u]>>t[u]>>k;
    }
        if(n[1]==d[1] && m[1]==a[1]){
            cout<<"1";
            if(b[1]==o[1] && p[1]==t[1]){
                cout<<"1";
                if(s>='A' && s<='C' && k>='A' && k<='C' || s>='D' && s<='F' && k>='D' && k<='F'){
                    cout<<"1";
                    if(max(s-'A',k-'A')-min(s-'A',k-'A')==1){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    cout<<"0"<<"0";
                }
            }else{
                cout<<"0"<<"0"<<"0";
            }
        }else{
            cout<<"0"<<"0"<<"0"<<"0";
        }
    return 0;
}
