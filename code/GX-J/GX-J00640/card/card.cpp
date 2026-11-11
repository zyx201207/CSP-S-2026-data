#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];

bool t[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(t[a[i]]==1){
            a[i]=a[1+i];
        }
        else{
            t[a[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(t[a[i]]==1){
            cout <<a[i];
        }
    }
    return 0;
}
