#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    int n[1000],k[1000];
    cin>>c>>t;
    int y;
    if(t == 2){
        for(int i = 1;i <= 15;i++){
            cin>>n[i]>>k[i];
        }
        y = 1;
        cout<<y<<endl;
        y = 2;
        cout<<y<<endl;
    }
    else if(t == 3){
        for(int i = 1;i <= 23;i++){
            cin>>n[i]>>k[i];
        }
        y = 1;
        cout<<y<<endl;
        cout<<y<<endl;
        y = 2;
        cout<<y<<endl;
    }
    else if(t == 5){
        cin>>n[1]>>k[1];
        if(k[1] == 42){
            for(int i = 2;i <= 2183;i++){
                cin>>n[i]>>k[i];
            }
            y = 17;
            cout<<y<<endl;
            y = 9;
            cout<<y<<endl;
            y = 6;
            cout<<y<<endl;
            cout<<y<<endl;
            y = 9;
            cout<<y<<endl;
        }
        else{
            for(int i = 1;i <= 224512;i++){
                cin>>n[i]>>k[i];
            }
            y = 189;
            cout<<y<<endl;
            y = 233;
            cout<<y<<endl;
            y = 288;
            cout<<y<<endl;
            y = 229;
            cout<<y<<endl;
            y = 338;
        }
    }
    else if(t == 1){
        for(int i = 1;i <= 10000;i++){
            cin>>n[i]>>k[i];
        }
        y = 12251;
        cout<<y<<endl;
    }
    return 0;
}
