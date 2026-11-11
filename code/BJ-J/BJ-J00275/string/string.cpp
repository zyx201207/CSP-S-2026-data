#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,a[MAXN],r,sum;
char c[MAXN];
vector<pair<long long,char> >v1,v2;
set<long long>se1,se2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];
    }
    sum=a[n]/2;
    for(int i=1;i<=n;i++){
        if(a[i]<=sum){
            v1.push_back({a[i],c[i]});
            se1.insert(a[i]);
        }
        if(a[i-1]+1<=sum&&a[i]>sum+a[n]%2){
            v1.push_back({sum,c[i]});
            se1.insert(sum);
            v2.push_back({sum-(a[i]-sum-a[n]%2)+1,c[i]});
            se2.insert(sum-(a[i]-sum-a[n]%2)+1);
        }
        if(a[i-1]+1>=sum+a[n]%2){
            v2.push_back({sum-(a[i]-sum-a[n]%2)+1,c[i]});
            se2.insert(sum-(a[i]-sum-a[n]%2)+1);
        }
    }
    sort(v2.begin(),v2.end());
    set<pair<long long,char> >se3;
    for(int i=0;i<v1.size();i++){
        if(!se2.count(v1[i].first)){
            int l=0,r=v2.size(),res=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(v2[mid].first>v1[i].first){
                    res=v2[mid].second;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            se3.insert(v1[i]);
        }
    }
    set<pair<long long,char> >se4;
    for(int i=0;i<v2.size();i++){
        if(!se2.count(v2[i].first)){
            int l=0,r=v1.size(),res=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(v1[mid].first>v2[i].first){
                    res=v1[mid].second;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            se4.insert(v2[i]);
        }
    }
    for(auto i:se3){
        v1.push_back(i);
    }
    for(auto i:se4){
        v2.push_back(i);
    }
    long long ans=0;
    for(int i=0;i<v1.size();i++){
        if(v1[i].second!=v2[i].second){
            if(i==0) ans+=v1[i].first;
            else ans+=v1[i].first-v1[i-1].first;
        }
    }
    cout<<ans;
    return 0;
}
