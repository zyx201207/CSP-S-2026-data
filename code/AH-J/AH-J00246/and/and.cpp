#include<iostream>
#include<cstdio>
using namespace std;
int a[200005],maxn=-0x3f3f3f3f;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=a[i];
        for(int j=i+1;j<=n;j++){
            cnt&=a[i];
            maxn=max(maxn,cnt);
        }
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
