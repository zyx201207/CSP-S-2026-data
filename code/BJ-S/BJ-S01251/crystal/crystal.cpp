#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,mid;vector<pair<long long,long long>>b;bool p;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p=1;
        if(b.size()==0){b.push_back({a[i],1});mid=0;continue;}
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j].first){
                p=0;
                b[j].second++;
                if(b[j].second>b[mid].second||(b[j].second==b[mid].second&&b[j].first>b[mid].first))mid=j;
                break;
            }
        }
        if(p){
            b.push_back({a[i],1});
        }
    }
    sort(a+1,a+n+1);
    ans=0;
    if(b[mid].second==1)mid=a[int(n*1.0/2+0.5)];
    else mid=b[mid].first;
    for(int i=n;i>=1;i--){
        if(m>=mid-a[i]&&mid-a[i]>=0){
            m-=mid-a[i];
            ans++;
        }
        else if(mid-a[i]>0)break;
    }
    cout<<ans;
    return 0;
}
