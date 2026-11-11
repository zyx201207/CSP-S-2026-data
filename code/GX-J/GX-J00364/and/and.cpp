#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int and(int x,int y){
    return min(x,y);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int mx=0;
        int sum=and;
        if(sum>mx){
            mx=sum;
        }
    }
    cout<<mx;
    return 0;
}

