//GZ-J00196 黄钰涵 贵阳市观山湖外国语实验中学
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c,z,c1,z2;
cin>>c>>z>>c1>>z2;
if(c==c1){
    cout<<'1';
}else{
cout<<'0';
}
string p=z.substr(0,2),p2=z2.substr(0,2);
if(p==p2 && c==c1){
    cout<<'1';
}else{
    cout<<'0';
}
p=z.substr(2);p2=z2.substr(2);
if( c==c1 && p=="A" || p=="B" || p=="C" && p2=="A" ||  p2=="B" || p2=="C" ){
    cout<<'1';
    }else if( c==c1 && p=="D" || p=="E" && p2=="D" || p2=="E"){
    cout<<'1';
    }else{
    cout<<'0';
    }
if( c==c1 && p=="A" || p=="C"&& p2=="B"){
    cout<<'1';
    }else if( c==c1 && p2=="D" && p=="E" || p=="D" && p2=="E"){
    cout<<'1';
    }else if( c==c1 && p=="B" && p2=="A"|| p2=="C" ){
    cout<<'1';
    }else{
    cout<<'0';
        }

fclose(stdin);
fclose(stdout);
return 0;
}
