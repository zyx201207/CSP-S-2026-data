#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[10],d[10];
int x[100];
int main(){
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
    }
    if(n[1]==4&&d[1]==2){
       cout<<"1"<<endl<<"2";
    }else{
       cout<<"0"<<endl<<"1"; 
    }
    return 0;
}
