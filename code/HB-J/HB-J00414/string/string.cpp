#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int d,e,g,ans;
struct aa{
    string s;
    int m;
}f[27];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>d;
    for(int i=1;i<=d;i++){
        cin>>e>>c;
        for(int i=1;i<=27;i++){
            if(f[i].s==""){
                f[i].s=c;
                f[i].m+=e;
                break;
            }
            if(f[i].s==c){
                f[i].m+=e;
                break;
            }
        }
        g+=e;
        for(int j=1;j<=e;j++) a+=c;
//        cout<<a<<endl;
    }
    for(int i=1;i<=26;i++)
        for(int j=1;j<=f[i].m;j++) b+=f[i].s;
    for(int i=0;i<g;i++)
        if(a[i]!=b[i]) ans++;
    if(ans%2==1){
        ans/=2;
        ans+=1;
    }
    else ans/=2;
    cout<<ans;
    return 0;
}
//a 49
