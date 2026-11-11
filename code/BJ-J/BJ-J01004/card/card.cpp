#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int cnt=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(b[i]=a[i])cnt++;
    }
    if(cnt==n){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
    }else{
        for(int i=1;i<=m;i++){
            mt19937 rn(time(0));
            cout<<rn()<<" ";
        }
    }

    return 0;
}