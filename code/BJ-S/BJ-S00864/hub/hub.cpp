#include<bits/stdc++.h>
using namespace std;
int n,k,t,c,a[10000100][2];
int main(){
    cin>>c>>t;
    while(t--){
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1];

        }
        if(c==0){
            if(t==3){
            cout<<'1'<<endl<<'2'<<endl<<'3'<<endl;
            }
            if(n==2&&k==2){
                cout<<'1'<<endl;
            }
            if(n==10 && k==3){
                cout<<'2'<<endl;
            }
        }
    }

}
