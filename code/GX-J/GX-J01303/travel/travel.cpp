#include <bits/stdc++.h>
using namespace std;
int a[4];
char c,s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    for(int i=0;i<4;i++){
        cin>>a[i];
        if(i==1){
            cin>>c;
        }
        else{
            cin>>s;
        }
    }

    if(a[0]==a[2]){
        cout<<1;
        if(a[1]==a[3]){
            cout<<1;
            if((c=='D'&&s=='F')||(c=='F'&&s=='D')||((c=='A'||c=='B'||c=='C')&&(s=='A'||s=='B'||s=='C'))){
                cout<<1;
                if(int(c)-int(s)==1||int(s)-int(c)==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }







    return 0;
}
