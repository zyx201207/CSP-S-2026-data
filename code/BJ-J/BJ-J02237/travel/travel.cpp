#include<bits/stdc++.h>
using namespace std;
int in1,in3;
string in2,in4;
int main(){
    cin>>in1>>in2>>in3>>in4;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(in1==in3){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(int(in2[0])*10+int(in2[1])==int(in4[0])*10+int(in4[1])) cout<<1;
    else cout<<0;
    if((in2[2]<='C'&&in4[2]<='C')||(in2[2]>='D'&&in4[2]>='D'))cout<<1;
    else cout<<0;
    if((int(in2)-int(in4)==1)||(int(in4)-int(in2)==1)||(in2[2]=='F'&&in4[2]=='D')||(in2[2]=='D'&&in4[2]=='F')){
        cout<<1;
    }else cout<<0;
    
    return 0;
}
