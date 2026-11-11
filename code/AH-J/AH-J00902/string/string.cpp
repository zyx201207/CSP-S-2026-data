#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char s[200005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],cin>>s[i];
    for(int i=1,j=n;i<j;i++){
        while(a[i]&&i<j){
            if(s[i]==s[j]){
                if(a[i]<a[j]){
                    a[j]-=a[i];
                    break;
                }
                a[i]-=a[j];
                j--;
            }else{
                if(a[i]<a[j]){
                    a[j]-=a[i];
                    ans+=a[i];
                    break;
                }
                a[i]-=a[j];
                ans+=a[j];
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
