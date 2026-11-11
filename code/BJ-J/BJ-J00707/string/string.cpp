#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,len,ans;
int a[N],c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        len+=a[i];
        char ch;
        cin>>ch;
        c[i]=ch-'a';
    }
    int i=0,l=0,lst,r=n+1,suml=0,sumr=0;
    while(l<r){
        lst=i+1;
        if(suml<sumr){
            l++;
            suml+=a[l];
            i=min(suml,sumr);
        }
        else if(suml>sumr){
            r--;
            sumr+=a[r];
            i=min(suml,sumr);
        }
        else{
            l++;r--;
            suml+=a[l];
            sumr+=a[r];
            i=min(suml,sumr);
        }
        if(l>=r) break;
        if(c[l]!=c[r]) ans+=i-lst+1;
    }
    cout<<ans;
    return 0;
}
