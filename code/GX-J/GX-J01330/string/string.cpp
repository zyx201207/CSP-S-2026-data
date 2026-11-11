#include <bits/stdc++.h>
using namespace std;
string fuck;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        char s;
        cin>>m>>s;
        for(int j=0;j<m;j++){
            fuck+=s;
        }
    }
    if(fuck.size()%2 != 0){
        int zj=fuck.size()/2;
        char zuo,you;
        int x=fuck.size();
        for(int i=0;i<zj;i++){
            zuo=fuck[i];
            you=fuck[i+x-1];
            if(zuo!=you) ans++;
            x--;
        }
    }else{
        int fg=fuck.size()/2;
        char zuo,you;
        int x=fuck.size();
        for(int i=0;i<fg;i++){
            zuo=fuck[i];
            you=fuck[i+x-2];
            if(zuo!=you) ans++;
            x--;
        }
    }
    cout<<ans;
    return 0;
}
