#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+1;
long long n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=1;
    sort(a+1,a+1+n);
    int p=a[n];
    int ans=0;
    if(m==1){
        cout<<p;
        return 0;
    }
    for(int i=n-1;i>=1;i--)
    {
        p=p&a[i];
        cnt++;
        if(cnt==m){
            cout<<p;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
