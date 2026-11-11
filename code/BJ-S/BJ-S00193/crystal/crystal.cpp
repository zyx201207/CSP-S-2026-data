#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,x=1,a[500005],b[500005];
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for (int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for (int i=1,j=1;i<n,j<=n;i++,j++){
        if ((m!=0&&m>=i*b[i])||(m==0&&b[i]==0)){
            if (m!=0&&m>=i*b[i]){
                m-=i*b[i];
                b[i]=0;
                a[j]=a[j+1];
            }
            else if (m==0&&b[i]==0){
                a[j]=a[j+1];
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]==a[i+1]) x+=1;
    }
    cout<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}