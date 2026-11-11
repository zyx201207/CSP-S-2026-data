#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    if(n>=100000){
        int ans=a[0];
        for(int i=1;i<m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int maxx=0;
    for(int i=0;i<n-m+1;i++){
        ans=a[i];
        for(int j=i+1;j<m+i;j++){
            ans=ans&a[i];
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
