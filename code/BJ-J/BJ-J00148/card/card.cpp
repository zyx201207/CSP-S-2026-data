#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[15],ans1,ans2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)ans1++;
        if(a[i]==2)ans2++;

    }
    if(a[n]==1)ans1=n;
    else ans2=n;
    cout<<ans1<<" "<<ans2;
    return 0;
}
