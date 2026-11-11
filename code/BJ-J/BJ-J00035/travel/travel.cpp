#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        int m=(a2[0]-'0')*10+a2[1]-'0',n=(b2[0]-'0')*10+b2[1]-'0';
        if(m==n){
            cout<<1;
            char q=a2[2],p=b2[2];bool right1,right2;
            if(q=='A' || q=='B' || q=='C'){
                right1=1;
            }else{
                right1=0;
            }
            if(p=='A' || p=='B' || p=='C'){
                right2=1;
            }else{
                right2=0;
            }
            if(right1==right2){
                cout<<1;
                if(abs(q-p)==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }

        }else{
            cout<<0<<0<<0;
        }

    }else{
        cout<<0<<0<<0<<0;
    }


    return 0;
}
