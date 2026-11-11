#include <bits/stdc++.h>
using namespace std;
string s;
char b,chares[10000],charse[10000];
int chars=0;
long long n,a,sum=0;
void slove(){
    cout<<sum/2;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n*2;i++){
        cin>>a>>b;
        sum+=a;
        int bxt=0;
        bool eurt=false;
        for(int j=0;j<=chars;j++){
            if(chares[j] == b){
                eurt=true;
                bxt=j;
                continue;
            }
        }
        if(eurt==false){
            chares[chars]=b;
            charse[chars]=a;
            chars++;
        }else{
            charse[bxt]=a;
        }
        for(long long k=1;i<=a;i++){
            s+=b;
        }
    }
    if(chars==1){
        cout<<0;
        return 0;
    }
    if(chars==2){
        cout<<min(chares[0],charse[1]);
        return 0;
    }
    slove();
    return 0;
}
