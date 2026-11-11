#include<bits/stdc++.h>
using namespace std;

int v(char w){
    if(w=='A')return 1;
    if(w=='B')return 2;
    if(w=='C')return 3;
    if(w=='D')return 4;
    if(w=='F')return 6;
    return -1;
}


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool f1=true;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            f1=0;
            break;
        }
    }
    if(!f1){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;

    bool f2=true;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            f2=0;
            break;
        }
    }
    if(!f2){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;

    int a=v(s1[2]),b=v(s2[2]);
    if(a<=3&&b<=3){
        cout<<1;
        if(a-b==1||a-b==-1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(a>=4&&b>=4){
        cout<<"11"<<endl;
    }
    else{
        cout<<"00"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
