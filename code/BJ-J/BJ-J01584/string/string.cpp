#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int cnt=0;
ll a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char ch;
        cin>>x>>ch;
        if(ch==c[cnt]){
            a[cnt]+=x;
        }
        else{
            cnt++;
            a[cnt]+=x;
            c[cnt]=ch;
        }
    }
//    for(int i=1;i<=cnt;i++){
  //          cout<<a[i]<<' ';
  //  }
    int i=1,j=cnt;
    ll ans=0;
    while(i<j){
        //cout<<i<<' '<<j<<':';
        //cout<<a[i]<<' '<<a[j]<<'\n';
        if(a[i]>a[j]){
            ans+=a[j];
            a[i]-=a[j];
            j--;
        }
        else if(a[i]==a[j]){
            ans+=a[j];
            i++;
            j--;
        }
        else{
            a[j]-=a[i];
            ans+=a[i];
            i++;
        }
        //cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
