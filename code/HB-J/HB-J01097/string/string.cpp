#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+7;
long long a[N];
char c[N];
long long ans;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<=n,j>=1;){
        if(i>j) break;
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            a[j]-=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
