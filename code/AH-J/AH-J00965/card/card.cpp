#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
            if(a[i]!=4&&a[i]!=3){
                    cout<<a[i];
                    return 0;
            }
    }

 return 0;
}
