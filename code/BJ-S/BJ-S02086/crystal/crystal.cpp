#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,s,temp;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    temp=a[1];
    for(int i=1;i<=n;i++){
            while(m--){
            if(temp==a[i+1]){
               cnt++;
               temp+=a[i+1];
            }
            else{
            s=abs(temp-a[i+1]);
            temp+=s;
           }
    }
    cout<<cnt;
    return 0;
}
}
