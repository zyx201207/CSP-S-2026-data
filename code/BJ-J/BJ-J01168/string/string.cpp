#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
char s[N];
ll a[N];
ll n,res;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    ll l=1,r=n;
    while(r>l){
        if(s[l]==s[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        else{
            if(a[l]>a[r]){
                res+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                res+=a[l];
                a[r]-=a[l];
                l++;
            }
            else{
                res+=a[l];
                l++;
                r--;
            }
        }
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
