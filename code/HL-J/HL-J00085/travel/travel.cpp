#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<2;i++){
        b=b*10+b1[i]-'0';
        a=a*10+a1[i]-'0';
        c=c*10+a2[i]-'0';
        d=d*10+b2[i]-'0';
    }
    int y=a2[2]-'A'+1,z=b2[2]-'A'+1;
    if(a==b){
        cout<<1;
        if(c==d){
            cout<<1;
            if(y+z==9 || (y+z<6 && ((y!=4 || z!=1) && (y!=1 || z!=4)))){
                cout<<1;
                if(y==z+1 || y==z-1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
