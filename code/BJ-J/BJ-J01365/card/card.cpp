#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn],b,c[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==2){
        for(int i=0;i<n;i++){
            if(a[i]==1)b++;
        }
        if(a[n-1]==1)cout<<n<<" "<<(n-b);
        else cout<<b<<" "<<n;
    }
    else{
        for(int i=0;i<n;i++){
            c[a[i]]=i;
        }
        for(int i=1;i<m;i++){
            cout<<c[i]+1<<" ";
        }
    }
    return 0;
}
