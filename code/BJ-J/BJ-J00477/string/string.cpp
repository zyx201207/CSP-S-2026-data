#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    string a={},b={};
    for(int i=1;i<=n;i++){
        int c;
        char d;
        cin>>c;
        cin>>d;
        for(int j=1;j<=c;j++){
            a+=d;
        }
    }
    b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<=n;i++){
        if(a[i]!=b[i]) cnt++;
    }
    cnt/=2;
    cout<<cnt;
    return 0;
}
