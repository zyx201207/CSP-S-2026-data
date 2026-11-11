#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,a[N],ans;
char c[N];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<j){
        if(c[i]==c[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }else{
                i++,j--;
            }
        }else{
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }else{
                ans+=a[i];
                i++,j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
