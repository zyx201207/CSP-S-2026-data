#include<bits/stdc++.h>
using namespace std;
const int max_len=5,Max=200005;
int a[Max],cnt[max_len];
int m,n;
int ans=0,num=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<max_len;i++){
        for(int j=0;j<n;j++){
            if(a[j]&1==1)
                cnt[i]++;
            a[j]>>=1;
        }
        
    }
    for(int i=max_len-1;i>-1&&num<m;i--){
        if(cnt[i]>=m){
            ans+=(1<<i);
            num++;
        }
    }
    cout<<ans;
    return 0;
}
