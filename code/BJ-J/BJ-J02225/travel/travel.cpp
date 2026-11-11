#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            if((c[2]-'A'<=2&&d[2]-'A'<=2)
            ||(c[2]-'A'>=3&&d[2]-'A'>=3)){
                cout<<1;
                if(!((c[2]=='A'&&d[2]=='C')||(c[2]=='C'&&d[2]=='A')))cout<<1;
                else cout<<"0";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
