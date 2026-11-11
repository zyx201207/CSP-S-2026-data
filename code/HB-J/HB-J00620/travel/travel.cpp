
#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int pai1,lie1,pai2,lie2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    pai1=(c[0]-'0')*10+c[1]-'0';
    lie1=c[2]-'A'+1;
    if(lie1==6) lie1--;
    pai2=(d[0]-'0')*10+d[1]-'0';
    lie2=d[2]-'A'+1;
    if(lie2==6) lie2--;
    if(pai1!=pai2){
        cout<<"1000";
        return 0;
    }
    if(lie1>=4&&lie2>=4){
        cout<<"1111";
        return 0;
    }
    if(lie1>=4&&lie2<=3){
        cout<<"1100";
        return 0;
    }
    if(lie1<=3&&lie2>=4){
        cout<<"1100";
        return 0;
    }
    if(lie1-lie2==2||lie2-lie1==2){
        cout<<"1110";
        return 0;
    }
    else{
        cout<<"1111";
    }
    return 0;
}
