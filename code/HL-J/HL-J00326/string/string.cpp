#include<bits/stdc++.h>
using namespace std;
struct nn{
    long long shul;
    char cc;
}a[200010];
long long l,r,n,ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].shul>>a[i].cc;
    }
    l=0;
    r=n-1;
    while(l<r){
        if(a[l].cc!=a[r].cc){
            ans+=a[l].shul;
        }
        l++;
        r--;
    }
    cout<<ans;
}
