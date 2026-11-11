#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int g=a[2]-a[1],l=1;
    while(m>0){
        if(m-l*g>=0){
            m-=l*g;
            l++;
        }
        else{
            break;
        }
    }
    cout<<l;
    return 0;
}
