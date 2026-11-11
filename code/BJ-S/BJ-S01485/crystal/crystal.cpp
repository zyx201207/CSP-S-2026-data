#include <bits/stdc++.h>
using namespace std;

long long n,m,a[600100],h[600100],r,l,mn,mid,ans;
bool check(long long x,long long y){
    if(a[y]*(y-mid+1)-h[y]+h[x-1]<=m){
        return true;
    }else{
        return false;
    }
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    //cout << 1<<endl<<endl;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mn=min(mn,a[i]);
    }
    //cout << 1<<endl<<endl;
    sort(a+1,a+1+n);
    
    //cout << 1<<endl<<endl;
    for(int i=1;i<=n;i++){
		//a[i]-=mn-1;
        h[i]=h[i-1]+a[i];
        //cout << a[i] << ' ';
    }
    for(int i=2;i<=n;i++){
        l=1;
        r=i;
        mid=(r+l)/2;
        while(l<=r){
            if(check(mid,i)){
				//cout << r;
                r=mid-1;
                ans=max(i-mid+1,ans);
            }else{
                l=mid+1;
				//cout << l;
            }
            mid=(r+l)/2;
        }
    }
    cout << ans;




    return 0;
}
