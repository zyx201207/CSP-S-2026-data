#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;


    if(c1[0]-'0'==s1[0]-'0'&&c1[1]-'0'==s1[1]-'0'){
        cout<<1;
    }  else{
        cout<<"0000";
        return 0;
    }
    //cout<<4<<" ";
    if(c2[0]-'0'==s2[0]-'0'&&c2[1]-'0'==s2[1]-'0'){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    //cout<<4<<" ";

    int sum1=c2[2]-'A',sum2=s2[2]-'A';
    if(sum1<=2&&sum2<=2){
        cout<<1;
    } else if(sum1>=3&&sum1<=4&&sum2>=3&&sum2<=4){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    //cout<<4<<" ";

    if(abs(sum1-sum2)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    //cout<<4<<" ";


   return 0;
}
