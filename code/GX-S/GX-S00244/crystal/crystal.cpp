#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),greater<long long>());
    for(int i=1;i<=n;i++){
        long long cnt=m;
        bool fl=true;
        int sum=0;
        for(int j=i;j<=n;j++){
            int b=a[j];
            while(b<a[i]&&cnt!=0){
                b++;
                cnt--;
            }
            if(b==a[i]) sum++;
            if(m==0) fl=false;
            if(!fl) break;
        }
        ans=max(ans,sum);
    }
    cout << ans;
    return 0;
}
