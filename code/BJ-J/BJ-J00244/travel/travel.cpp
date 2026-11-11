#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ans[4];
string a,b,c,d;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        ans[0]=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            ans[1]=1;
            if(b[2]>='A'&&b[2]<='C'){
                if(d[2]>='A'&&d[2]<='C'){
                    ans[2]=1;
                    if(b[2]-d[2]==1||d[2]-b[2]==1){
                        ans[3]=1;
                    }
                }
            }
            else if(b[2]=='D'||b[2]=='F'){
                if(d[2]=='D'||d[2]=='F'){
                    ans[2]=1;
                    ans[3]=1;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
