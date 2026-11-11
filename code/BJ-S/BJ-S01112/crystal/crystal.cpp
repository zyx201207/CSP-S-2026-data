#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mid=(1+n)/2;
    for(int j=1;j<mid;j++){
        int cnt=0;
        for(int i=1;i<mid;i++){
            cnt+=a[mid]-a[i];
        }
        if(cnt<m){
             mid++;
        }else if(cnt>m){
            mid--;
        }else{
            cout<<mid;
        }

    }

    return 0;
}
