#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    int x,y;
    string ch1,ch2;
    cin>>c1>>ch1>>c2>>ch2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    x=(ch1[0]-'0')*10+ch1[1]-'0',y=(ch2[0]-'0')*10+ch2[1]-'0';
    if(x!=y){
        cout<<"1000"<<endl;
        return 0;
    }
    if((ch1[2]>='A'&&ch1[2]<='C'&&ch2[2]>='D'&&ch2[2]<='F')||(ch2[2]>='A'&&ch2[2]<='C'&&ch1[2]>='D'&&ch1[2]<='F')){
        cout<<"1100"<<endl;
        return 0;
    }
    if((ch1[2]=='A'&&ch2[2]=='C')||(ch1[2]=='C'&&ch2[2]=='A')){
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
