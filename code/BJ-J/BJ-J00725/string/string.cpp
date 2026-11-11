#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n,l,a[MAXN],b[MAXN],ans;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string6.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i]>>c;
        b[i]=c-'a';
        l+=a[i];
    }
    ll i=0,j=n+1,k1=0,k2=0,p=0;
    while(p<(l-1)/2){
        if(k1==0){
            i++;
            k1=a[i];
        }else{
            j--;
            k2=a[j];
        }
        ll min_=min(k1,k2);
        if(b[i]!=b[j]&&(i>0)&&(j<n+1)){
            ans+=min_;
        }
        p+=min_;
        k1-=min_;
        k2-=min_;
    }
    cout<<ans;
    return 0;
}

