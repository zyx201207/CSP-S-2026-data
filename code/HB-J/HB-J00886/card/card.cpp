#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    int sum=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            sum++;
        }else{
            cout<<sum<<" ";
            sum=1;
        }
    }
    return 0;
}

