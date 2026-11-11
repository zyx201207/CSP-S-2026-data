#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],b=1,e,ans=0;
char ch[200001];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    e = n;
    while(b<e){
        if(ch[b]==ch[e]){
            if(a[b]>a[e]){
                a[b] -= a[e];
                e--;
            }
            else{
                a[e] -= a[b];
                b++;
            }
        }
        else{
            if(a[b]>a[e]){
                a[b] -= a[e];
                e--;
                ans += a[e+1];
            }
            else{
                a[e] -= a[b];
                b++;
                ans += a[b-1];
            }
        }
    }
    cout<<ans;

    return 0;
}
