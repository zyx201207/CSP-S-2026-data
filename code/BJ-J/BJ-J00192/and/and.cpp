#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b){
    if(a>=b) return 1;
    else return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    long long int n,m,a[200005],ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    ans+=a[0];
    for(int i=1;i<m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}