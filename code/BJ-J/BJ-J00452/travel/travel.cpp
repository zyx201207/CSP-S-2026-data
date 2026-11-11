#include<bits/stdc++.h>
using namespace std;
// long long read(){
//     long long x=0;
//     bool ji=0,flag=0;
//     char a;
//     while(1){
//         a=getchar_unlocked();
//         if(a=='-') ji=1;
//         else if(isdigit(a)){
//             x=(x<<1)+(x<<3)+a-'0';
//             flag=1;
//         }else if(flag) break;
//     }
//     if(ji) x=-x;
//     return x;
// }
string cx1,cx2,zw1,zw2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx1>>zw1>>cx2>>zw2;
    if(cx1==cx2){
        cout<<"1";
        if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
            cout<<"1";
            if((zw1[2]<='C')^(zw2[2]<='C')){
                cout<<"00";
            }else{
                cout<<'1';
                if(zw1[2]-zw2[2]<=1) cout<<'1';
                else cout<<'0';
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}