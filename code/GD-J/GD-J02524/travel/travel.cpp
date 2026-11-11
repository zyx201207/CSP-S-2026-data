#include<bits/stdc++.h>
using namespace std;
 int s[5];
int main(){
    freopen("travel.in ","r",stdin);
    freopen("travel.out ","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        s[1]=1;
        if(b[1]==d[1]&&b[0]==d[0]){
            s[2]=1;
            if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
                s[3]=1;
                if(b[2]-d[2]==1||b[2]-d[2]==-1){
                    s[4]=1;

                }

            }
        }
    }
    for(int i=1;i<=4;i++)cout<<s[i];
    cout<<endl;
    return 0;
}
