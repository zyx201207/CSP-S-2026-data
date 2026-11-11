#include <bits/stdc++.h>
int n,m;
using namespace std;
long long a[5+(int)5e5];
long long b[5+(int)5e5];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n>5000){
        int cha=a[2]-a[1];
        m=m/cha;
        for(int i=1;i<=n;i++){
            if(i>=m){
                m-=i;
                ans++;
            }
            if(i<m)break;
        }
        cout<<ans;
        return 0;
        fclose(stdin);
        fclose(stdout);
    }
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        int tas=0;
        int j;
        for(j=i;j>0;j--){
            if((tas*2+b[i])<m)tas=tas*2+b[i];
            else break;
        }
        ans=max(ans,j);
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
