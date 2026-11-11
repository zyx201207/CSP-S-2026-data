#include <bits/stdc++.h>
using namespace std;

struct str{
    long long n;
    char c;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    str a[t];
    long long len=0;
    for(int i=0;i<t;i++){
        cin>>a[i].n>>a[i].c;
        len+=a[i].n;
    }
    int l=0,r=t-1;
    long long ans=0;
    long long p=a[l].n;
    long long q=a[r].n;
    while(l<r){
        if(a[l].c!=a[r].c){
            if((ans+q)>(len/2)) ans=len/2;
            else ans+=q;
        }
        if(p>q){
            p-=q;
            r--;
            q=a[r].n;
        }
        else{
            q-=p;
            l++;
            p=a[l].n;
        }
    }
    cout<<ans;
    return 0;
}
