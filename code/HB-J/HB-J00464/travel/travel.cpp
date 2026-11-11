#include<bits/stdc++.h>
using namespace std;
char c[20],d[20],e[20],f[20];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>d>>e>>f;
    int u=strlen(c);
    int v=strlen(d);
    int w=strlen(e);
    int x=strlen(f);
    for(int i=0;i<u;i++){
        if(c[i]!=e[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<'1';
    for(int i=0;i<v-1;i++){
        if(d[i]!=f[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<'1';
    if((d[v-1]<'D'&&f[v-1]<'D')||(d[v-1]>'C'&&f[v-1]>'C')){
            cout<<'1';
    }
    else{
        cout<<"00";
        return 0;
    }
    if(d[v-1]-1==f[v-1]||d[v-1]+1==f[v-1]){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    return 0;
}
