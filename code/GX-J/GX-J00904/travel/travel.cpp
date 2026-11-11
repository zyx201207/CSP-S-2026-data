#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,w1,c2,w2;
    cin>>c1>>w1>>c2>>w2;
    if(c1==c2){
        cout<<1;
        int ww1=((w1[0]-'0')*10)+(w1[1]-'0');
        int ww2=((w2[0]-'0')*10)+(w2[1]-'0');
        if(ww1==ww2){
                cout<<1;
                if(w1[2]=='A'){
                    if(w2[2]=='B'){
                        cout<<"11";
                    }
                    if(w2[2]=='C'){
                        cout<<"10";
                    }
                    if(w2[2]=='D'){
                        cout<<"00";
                    }
                    if(w2[2]=='F'){
                        cout<<"00";
                    }
                }
                else if(w1[2]=='B'){
                    if(w2[2]=='A'){
                        cout<<"11";
                    }
                    if(w2[2]=='C'){
                        cout<<"11";
                    }
                    if(w2[2]=='D'){
                        cout<<"00";
                    }
                    if(w2[2]=='F'){
                        cout<<"00";
                    }
                }
                else if(w1[2]=='C'){
                    if(w2[2]=='A'){
                        cout<<"10";
                    }
                    if(w2[2]=='B'){
                        cout<<"11";
                    }
                    if(w2[2]=='D'){
                        cout<<"00";
                    }
                    if(w2[2]=='F'){
                        cout<<"00";
                    }
                }
                else if(w1[2]=='D'){
                    if(w2[2]=='A'){
                        cout<<"00";
                    }
                    if(w2[2]=='B'){
                        cout<<"00";
                    }
                    if(w2[2]=='C'){
                        cout<<"00";
                    }
                    if(w2[2]=='F'){
                        cout<<"11";
                    }
                }
                else if(w1[2]=='F'){
                    if(w2[2]=='A'){
                        cout<<"00";
                    }
                    if(w2[2]=='B'){
                        cout<<"00";
                    }
                    if(w2[2]=='C'){
                        cout<<"00";
                    }
                    if(w2[2]=='D'){
                        cout<<"11";
                    }
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
