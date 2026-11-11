#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string c1,s1,c2,s2; 
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    int x1=(c1[0]-'0')*10+c1[1]-'0';
    int x2=(c2[0]-'0')*10+c2[1]-'0';
    // cout<<x1<<" "<<x2<<endl;
    if(s1==s2){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    if(x1==x2){
        cout<<1;
    }else{
        cout<<"000"<<endl;
        return 0;
    }
    int Y1=c1[2]-'A'+1;
    int Y2=c2[2]-'A'+1;
    if((1<=Y1 && 1<=Y2 && Y1<=3 && Y2<=3) || (4<=Y1 && 4<=Y2 && Y1<=6 && Y2<=6)){
        cout<<1;
    }else{
        cout<<"00"<<endl;
        return 0;
    }
    if(1<=Y1 && 1<=Y2 && Y1<=3 && Y2<=3 && abs(Y1-Y2)==1){
        cout<<1<<endl;
    }else if(4<=Y1 && 4<=Y2 && Y1<=6 && Y2<=6){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}