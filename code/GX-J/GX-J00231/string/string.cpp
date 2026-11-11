#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
int n,a[N];
char c[N];
ll ans,cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=n;j>i&&a[i];j--)
            if(c[i]==c[j]){
                if(a[i]>=a[j])a[i]-=a[j],a[j]=0,n--;
                else {a[j]-=a[i];a[i]=0;}
            }else{
                if(a[i]>=a[j]){ans+=a[j];a[i]-=a[j],a[j]=0;n--;}
                else{
                    ans+=a[i];
                    a[j]-=a[i];a[i]=0;
                }
            }
    cout<<ans<<endl;
    return 0;
}
