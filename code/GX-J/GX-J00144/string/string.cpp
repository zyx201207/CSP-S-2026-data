#include<bits/stdc++.h>
using namespace std;

long long n,a,cnt,h;
long long ans[100000005];
char ca;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int j=1; j<=n; j++){
        cin>>a>>ca;
        cnt+=a;
    }
    if(cnt<=3&&cnt>1){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
