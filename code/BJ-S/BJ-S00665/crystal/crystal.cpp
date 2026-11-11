#include <bits/stdc++.h>

using namespace std;
long long n,m;
long long a[500005];
bool my(int x,int y){
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,my);
    int k=0;
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i+1;j<n;j++){
            ans+=a[i]-a[j];
        }
        if(ans==m){
            k=n-i;
            break;
        }
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
