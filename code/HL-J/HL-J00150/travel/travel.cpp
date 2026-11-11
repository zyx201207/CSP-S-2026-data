#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string seat_1,seat_2;
int box_1,box_2;
cin>>box_1>>seat_1>>box_2>>seat_2;
if(box_1==box_2){
    cout<<1;
}else{
cout<<"0000";
return 0;
}
int cnt_1=0,cnt_2=0;
for(int i=0;i<2;i++){
    cnt_1=cnt_1*10+(int)seat_1[i];
    cnt_2=cnt_2*10+(int)seat_2[i];
}
if(cnt_1==cnt_2){
    cout<<1;
}else{
cout<<"000";
return 0;
}
char a,b;
a=seat_1[2];
b=seat_2[2];
char c=a++,d=b++;
if(c==b||a==d){
    if(a=='D'&&b=='E'){
        cout<<"00";
        return 0;
    }else if(a=='E'&&b=='D'){
        cout<<"00";
        return 0;
    }
    else{
        cout<<11;
        return 0;
    }
}
 if(a+2==b||a==b+2){
    cout<<10;
}


return 0;
}
