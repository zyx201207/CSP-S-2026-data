#include<bits/stdc++.h>
using namespace std;
struct amp{
    int c;
    int p;
    int z;
}a[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        string x;
        cin>>a[i].c>>x;
        a[i].p=(x[0]-'0')*10+x[1]-'0';
        a[i].z=x[2]-'A'+1;
    }
    if(a[1].c==a[2].c){
        cout<<'1';
        if(a[1].p==a[2].p){
            cout<<'1';
            if((a[1].z>=1&&a[1].z<=3)&&(a[2].z>=1&&a[2].z<=3)){
                cout<<'1';
                if(abs(a[1].z-a[2].z)==1||(a[1].z==4&&a[2].z==6)||(a[1].z==6&&a[2].z==4)) cout<<'1';
                else cout<<'0';
            }else if((a[1].z==4||a[1].z==6)&&(a[2].z==4||a[2].z==6)){
                cout<<'1';
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
