#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
 freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    char a[200000];
    ll s[200000];
    ll sum=0;
    ll p=0;
    int g=0;
    bool flag =true;
   for(ll i=0;i<n;i++){
        cin>>s[i]>>a[i];
        g+=s[i]%10;
   }if(g%2==1){
       flag=false;
   }
   ll l=0,r=n-1;
   while(true){
        if(flag==false){
            if(l==r){
                break;
            }
        }
            else{
                    if(l>r){
                       break;
                    }
                }

       if(s[l]==s[r]&&a[l]!=a[r]){
        sum+=s[r];
        r--;l++;
       }
       else if(s[l]>s[r]&&a[l]!=a[r]){
        s[l]-=s[r];
        sum+=s[r];
        r--;
       }else if(s[r]>s[l]&&a[l]!=a[r]){
           s[r]-=s[l];
        sum+=s[l];
        l++;
       }else if(a[l]==a[r]){
           if(s[l]<s[r]){
            s[r]-=s[l];
            l++;
           }if(s[l]==s[r]){
               l++;
               r--;
           }if(s[r]<s[l]){
               s[l]-=s[r];
               r--;
           }
       }
   }
    cout<<sum;
    return 0;
}
