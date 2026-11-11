#include<bits/stdc++.h>
using namespace std;
int lev(long long x){
    int cnt=0;
    while(x)x>>=1,cnt++;
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n,0);
    long long maxn=0;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a.begin(),a.end(),greater<long long>());
    long long mlev=lev(maxn);
    for(long long i=1LL<<mlev;i>0;i>>=1){
        long long ccnt=0;
        vector<long long> c;
        for(long long j=0;j<n;j++){
            if(a[j]&i)ccnt++,c.push_back(a[j]);
        }
        if(ccnt<m)continue;
        a.resize(0,0);
        for(long long i=0;i<c.size();i++)a.push_back(c[i]);
        n=c.size();
    }
    long long ans=a[0];
    for(long long i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
