#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[1]==d[1]&&b[0]==d[0]){
            cout<<1;
            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                    cout<<1;
                    if(abs(b[2]-d[2])==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }else{
                if(b[2]=='F'||b[2]=='D'){
                    cout<<1;
                    if(abs(b[2]-d[2])==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
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
