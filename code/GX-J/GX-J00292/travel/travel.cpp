#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s[10];
    int car[10];
    int seat01[100];
    int seatA[10];
    for(int i=1;i<=4;i++){
        cin>>s[i];
        //cout<<s[i]<<' ';//
    }//cout<<endl;//

    car[1]=(s[1][0]-'0')*10 + s[1][1]-'0';
    car[2]=(s[3][0]-'0')*10 + s[3][1]-'0';
    seat01[1]=(s[2][0]-'0')*10 + s[2][1]-'0';
    seat01[2]=(s[4][0]-'0')*10 + s[4][1]-'0';
    seatA[1]=s[2][2]-'A'+1;
    seatA[2]=s[4][2]-'A'+1;
    if(seatA[1]==6) seatA[1]--;
    if(seatA[2]==6) seatA[2]--;
    /*
    for(int i=1;i<=2;i++){
        cout<<car[i]<<' '<<seat01[i]<<' '<<seatA[i]<<endl;
    }//*/


    if(car[1]==car[2]){//cout<<"!!!!!";
        cout<<"1";
        if(seat01[1]==seat01[2]){
            cout<<"1";
            if( ( (seatA[1]<=3&&seatA[1]>=1) && (seatA[2]<=3&&seatA[2]>=1) )
              ||( (seatA[1]<=6&&seatA[1]>=4) && (seatA[2]<=6&&seatA[2]>=4) ) ){
                cout<<"1";
                int temp=abs(seatA[1]-seatA[2]);//cout<<temp;//
                if(temp==1 && seatA[1]+seatA[2]!=7){
                    cout<<"1";
                }else cout<<"1";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
