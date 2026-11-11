#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    ll ans=0;
    for(int i=1,j=n;i<j;){
        int na=a[i],nb=a[j];
        if(ch[i]==ch[j]){
            if(na==nb){
                i++;
                j--;
            }
            else if(na>nb){
                j--;
                a[i]=na-nb;
            }
            else{
                i++;
                a[j]=nb-na;
            }
        }
        else{
            if(na==nb){
                i++;
                j--;
                ans+=na;
            }
            else if(na>nb){
                a[i]=na-nb;
                j--;
                ans+=nb;
            }
            else{
                i++;
                a[j]=nb-na;
                ans+=na;
            }
        }
    }
    cout<<ans;
    return 0;
}
