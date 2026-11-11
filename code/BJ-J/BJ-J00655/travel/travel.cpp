#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+2;
struct NODE{
    string a;
}s1,s2;
char c1[maxn],c2[maxn];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s1.a>>c1[1]>>c1[2]>>c1[3]>>s2.a>>c2[1]>>c2[2]>>c2[3];
    if(s1.a!=s2.a){
        cout<<"0000"<<'\n';
    }else{
        cout<<1;
        if(c1[1]!=c2[1]||c1[2]!=c2[2]){
            cout<<"000"<<'\n';
        }
        else{
            cout<<1;
            if((c1[3]<='C'&&c2[3]>='D')||(c1[3]>='D'&&c2[3]<='C')){
                cout<<"00"<<'\n';
            }
            else{
                cout<<1;
                cout<<'\n'<<"c"<<'\n';
                if((c1[3]=='A'&&c2[3]=='C')||(c1[3]=='C'&&c2[3]=='A')){
                    cout<<0<<'\n';
                }else{
                    cout<<1<<'\n';
                }
            }
        }
    }
    return 0;
}
