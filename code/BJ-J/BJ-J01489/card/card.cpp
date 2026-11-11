#include<bits/stdc++.h>
using namespace std;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int n1=a[n-2],n2=a[n-1],n3=a[n];
    if(n2==n3){
        if(n3==1){
            cout<<0<<" "<<n;
        }
        else{
            cout<<n<<" "<<0;
        }
    }
    else{
        cout<<n<<" "<<n;
    }
    return 0;
}