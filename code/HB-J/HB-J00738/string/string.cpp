#include<bits/stdc++.h>
using namespace std;
unsigned long long num[30];
unsigned long long maxcmp(unsigned long long x,unsigned long long y){
    if(x>=y){
        return x;
    }
    else{
        return y;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    unsigned long long length=0;
    bool flag=true;
    int a1;
    char c1;
    cin>>a1>>c1;
    if(n==1){
        cout<<0;
        return 0;
    }
    else if(n==2){
        int a2;
        char c2;
        cin>>a2>>c2;
        if(c1==c2){
            cout<<0;
        }
        else{
            cout<<min(a1,a2);
        }
        return 0;
    }
    else{
        for(int i=2;i<=n;i++){
            int a;
            cin>>a;
            length+=a;
            char c;
            cin>>c;
            if(c!=c1){
                flag=false;
            }
            num[c]+=a;
        }
        if(flag==true){
            cout<<0;
        }
        else{
            unsigned long long max1=0;
            for(int i=1;i<=26;i++){
                max1=max(max1,num[i]);
            }
            cout<<length-max1;
        }
    }
    return 0;
}
