#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    for(int i=a[0];i<=a[n-1];i++){
        int m1 = m;
        int cnt=0;
        int b[n];
        for(int j=0;j<n;j++){
            b[j]=i-a[j];
        }
        sort(b,b+n);
        for(int j=0;j<n;j++){
            if(b[j]>=0){
                m1-=b[j];
                cnt++;
                if(m1<0){
                    cnt--;
                    break;
                }
            }
        }
        ans=max(ans,cnt);

    }
    cout<<ans;
    return 0;
}
