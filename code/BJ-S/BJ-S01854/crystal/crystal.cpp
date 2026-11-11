#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500006],b[500006];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    priority_queue<int> q;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for (int i=n;i>=1;i--){
        a[i]=q.top();
        q.pop();
    }
    for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
    int l=1,r=1;
    long long ans=0;
    int cnt=0;
    while (r<n){
        long long v=b[r]*(r-l+1);
        if (ans+v>m){
            while (ans+v>m){
                ans-=a[r]-a[l];
                v-=b[r];
                l++;
            }
            ans+=v;
            r++;
            cnt=max(cnt,r-l);
        }
        else{
            ans+=v;
            r++;
            cnt=max(cnt,r-l);
        }
    }
    cout<<cnt+1;
    return 0;
}
