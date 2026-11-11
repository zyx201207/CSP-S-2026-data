#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        int in=b.size();
        for(int i=0;i<2;i++){
            if(b[i]!=d[i]){
                cout<<"000";
                return 0;
            }
        }
        cout<<"1";
        for(int i=2;i<3;i++){
            if(b[i]=='A' && (d[i]=='B' || d[i]=='C') || b[i]=='B' && (d[i]=='A'||d[i]=='C') || b[i]=='C' && (d[i]=='A' || d[i]=='B') || b[i]=='D' && d[i]=='F' || b[i]=='F' && d[i]=='D'){
                cout<<"1";
            }else{
                cout<<"00";
                return 0;
            }
        }
        for(int i=2;i<3;i++){
            if(b[i]=='A' && d[i]=='B' || b[i]=='B' && (d[i]=='A'||d[i]=='C') || b[i]=='C' && d[i]=='B' || b[i]=='D' && d[i]=='F' || b[i]=='F' && d[i]=='D'){
                cout<<"1";
            }else{
                cout<<"0";
                return 0;
            }
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
