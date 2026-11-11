#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],z[500005],s[500005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    long long SS=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        c[i]=(i-1)*(a[i]-a[i-1])+c[i-1];
        z[i]=z[i-1]+a[i]-a[i-1];
        s[i]=s[i-1]+z[i];
        //cout<<c[i]<<" "<<z[i]<<" "<<s[i]<<endl;
    }
    long long l=0,r=0;
    cnt=0;
    /*for(int i=n;i>=2;i--){
        while(c[r]-z[r]*l+s[abs(l-1)]<m){
            l--;
            cnt++;
        }
        cnt--;
        SS=max(SS,cnt);
        r=i-1;
        l=i-2;
        cnt=1;
    }*/
    while(r<n){
        r++;
        cnt++;
        if(c[r]-z[r]*l+s[abs(l-1)]<=m){
            SS=max(SS,(r-l));
        }
        else{
            while(c[r]-z[r]*l+s[abs(l-1)]>m){
                l++;
                cnt--;
            }
        }
        /*if(c[r]-z[r]*l-c[r-1]+z[r-1]*l>c[r]-z[r]*l+s[abs(l-1)]-c[r]+z[r]*(l+1)-s[abs(l)]){
            r--;
            cnt--;
        }
        else{
            l++;
            cnt--;
        }*/

    }
    cout<<SS;
    return 0;
}
