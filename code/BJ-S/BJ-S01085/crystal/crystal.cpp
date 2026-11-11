#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long>a;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,biao=0,wei=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        long long b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    long long cnt=0;
    bool f=0;
    while(f==0){
        for(long long i=n-1;i>=0;i--){
            for(long long j=0;j<i;j++){
                long long c=a[i]-a[j];
                cnt+=c;

            }
            if(cnt<=m){
                biao=a[i];
                wei=i;
                f=1;
                break;
            }else{
                cnt=0;
            }

        }
    }

    long long num=0;
    for(long long i=0;i<=wei;i++){
        num++;
    }
    cout<<num;
    return 0;
}
