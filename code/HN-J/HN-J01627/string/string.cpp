#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,x;
char ax,bx;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>x;
        if(n==2){
            if(bx==x){
                cout<<0;
                return 0;
            }
            bx=x;

        }
        cin>>ax;
        for(int i=1;i<=x;i++){
            s+=ax;
        }
    }
    return 0;
}
