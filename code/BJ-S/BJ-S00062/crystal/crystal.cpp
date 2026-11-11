#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans,lm,im,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    a[0]=a[1];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
    for(int i=1;i<=n;i++){
        long long l=i,r=n,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(s[mid]-s[i]>m)
                r=mid-1;
            else
                l=mid;
            //cout << l << " " << r << endl;
        }
        //cout << ans << endl;
        if(ans<l-i+1){
            ans=l-i+1;
            c=m-s[l]+s[i];
            lm=l;
            im=i;
        }
    }
    //for(int i=lm;i<=n and a[i]==a[lm];i++)
    //    ans++;
    cout << ans;

    return 0;
}
