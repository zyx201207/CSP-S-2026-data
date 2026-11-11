#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[18] = ["01A","02A","03A","04A","05A","06A","07A","08A","09A","10A","11A","12A","13A","14A","15A","16A","17A","18A"]
    char b[18] = ["01B","02B","03B","04B","05B","06B","07B","08B","09B","10B","11B","12B","13B","14B","15B","16B","17B","18B"]
    char c[18] = ["01C","02C","03C","04C","05C","06C","07C","08C","09C","10C","11C","12C","13C","14C","15C","16C","17C","18C"]
    char d[18] = ["01D","02D","03D","04D","05D","06D","07D","08D","09D","10D","11D","12D","13D","14D","15D","16D","17D","18D"]
    char e[18] = ["01E","02E","03E","04E","05E","06E","07E","08E","09E","10E","11E","12E","13E","14E","15E","16E","17E","18E"]
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        for(int i = 0;i<18;i++){
            if(a[i]==s1&&b[i]==s2){
                cout<<"111";
                break;
            }
            if(a[i]==s1&&c[i]==s2){
                cout<<"110";
                break;
            }
            if(a[i]==s1&&d[i]==s2){
                cout<<"100";
                break;
            }
            if(a[i]==s1&&e[i]==s2){
                cout<<"100";
                break;
            }
            if(b[i]==s1&&a[i]==s2){
                cout<<"111";
                break;
            }
            if(b[i]==s1&&c[i]==s2){
                cout<<"111";
                break;
            }
            if(b[i]==s1&&d[i]==s2){
                cout<<"100";
                break;
            }
            if(b[i]==s1&&e[i]==s2){
                cout<<"100";
                break;
            }
            if(c[i]==s1&&a[i]==s2){
                cout<<"110";
                break;
            }
            if(c[i]==s1&&b[i]==s2){
                cout<<"111";
                break;
            }
            if(c[i]==s1&&d[i]==s2){
                cout<<"111";
                break;
            }
            if(c[i]==s1&&e[i]==s2){
                cout<<"100";
                break;
            }
            if(d[i]==s1&&a[i]==s2){
                cout<<"100";
                break;
            }
            if(d[i]==s1&&b[i]==s2){
                cout<<"100";
                break;
            }
            if(d[i]==s1&&c[i]==s2){
                cout<<"111";
                break;
            }
            if(d[i]==s1&&e[i]==s2){
                cout<<"111";
                break;
            }
            if(e[i]==s1&&a[i]==s2){
                cout<<"100";
                break;
            }
            if(e[i]==s1&&b[i]==s2){
                cout<<"100";
                break;
            }
            if(e[i]==s1&&c[i]==s2){
                cout<<"100";
                break;
            }
            if(e[i]==s1&&d[i]==s2){
                cout<<"111";
                break;
            }
            if(i==17){
                cout<<"000";
            }
        }
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
