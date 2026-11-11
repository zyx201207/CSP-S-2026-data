#include<bits/stdc++.h>
using namespace std;
long long a,b;
char A[5],B[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    cin>>A[1]>>A[2]>>A[3];
    cin>>b;
    cin>>B[1]>>B[2]>>B[3];
    if(a==b){
        cout<<1;
        if(A[1]==B[1]&&A[2]==B[2]){
            cout<<1;
            if((A[3]>='A'&&A[3]<='C'&&B[3]>='A'&&B[3]<='C')||(A[3]>='D'&&A[3]<='F'&&B[3]>='D'&&B[3]<='F')){
                cout<<1;
                if((A[3]=='A'&&B[3]=='B')||(A[3]=='B'&&B[3]=='A')||(A[3]=='B'&&B[3]=='C')||(A[3]=='C'&&B[3]=='B')||(A[3]=='D'&&B[3]=='F')||(A[3]=='F'&&B[3]=='D')) cout<<1;
                else cout<<0;
            }
            else{cout<<0;cout<<0;}
        }
        else{cout<<0;cout<<0;cout<<0;}
    }
    else{cout<<0;cout<<0;cout<<0;cout<<0;}
    return 0;
}
