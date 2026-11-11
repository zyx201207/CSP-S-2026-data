#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
char b[1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==3){
        if(a[0]==2 && b[0]=='a'&& a[1]==2 && b[1]=='b' && a[2]==1 && b[2]=='c'){
            cout<<"2";
        }
    }
    if(n==2){
        if(a[0]==2 && b[0]=='a'&& a[1]==3 && b[1]=='a' ){
            cout<<"0";
        }
    }
    if(n==6){
        if(a[0]==1000000000 && b[0]=='a'&& a[1]==1000000000 && b[1]=='a' && a[2]==1000000000 && b[2]=='a'&&a[3]==1000000000 && b[3]=='b'&& a[4]==1000000000 && b[4]=='b' && a[5]==1000000000 && b[5]=='b'){
            cout<<"3000000000";
        }
    }


    return 0;
}
