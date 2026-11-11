#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        while(a[i]>0){
            if(a[i]<a[n]){
                if(c[i]!=c[n])sum+=a[i];
                a[n]-=a[i];
                a[i]=0;
            }else{
                if(c[i]!=c[n])sum+=a[n];
                a[i]-=a[n];
                a[n]=0;
                n--;
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}
