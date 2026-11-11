#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m;
long long a[N],ans=0xffffff;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>n-m-1;i--){
        ans=a[i]&ans;

        if(ans==0||ans<a[i-1]){
            n--;
            ans=0xffffff;
        }
    }
    cout<<ans;


    return 0;
}
