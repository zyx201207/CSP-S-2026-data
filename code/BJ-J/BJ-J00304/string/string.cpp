#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct node{
    int cnt;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
    }
    int l=1,r=n;
    long long ans=0;
    while(l<=r){
        if(a[l].c==a[r].c){
            if(a[l].cnt>a[r].cnt){
                a[l].cnt-=a[r].cnt;
                r--;
            }else if(a[l].cnt<a[r].cnt){
                a[r].cnt-=a[l].cnt;
                l++;
            }else{
                l++;
                r--;
            }
            //cout<<1<<' '<<ans<<'\n';
        }else{
            if(a[l].cnt>a[r].cnt){
                ans+=a[r].cnt;
                a[l].cnt-=a[r].cnt;
                r--;
            }else if(a[l].cnt<a[r].cnt){
                ans+=a[l].cnt;
                a[r].cnt-=a[l].cnt;
                l++;
            }else{
                ans+=a[l].cnt;
                l++;
                r--;
            }
            //cout<<0<<' '<<ans<<'\n';
        }
    }
    cout<<ans;
    return 0;
}
