#include<bits/stdc++.h>
using namespace std;

long long a[200005];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,cnt;
    long long x,maxx=0,ans;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(maxx<a[i]&a[j]) maxx=a[i]&a[j];
            }
        }
        cout<<maxx;
        return 0;
    }
    sort(a,a+n-1,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
