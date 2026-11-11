#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m=0;
    cin>>n;
    vector<pair<long long,char>> st(n);
    for(int i=0;i<n;i++){
        cin>>st[m].first>>st[m].second;
        if(st[m].second==st[m-1].second){
            st[m-1].first+=st[m].first;
            m--;
        }
        m++;
    }
    long long hc,t=0;
    long long l=0,r=m-1;
    long long ans=0;
    for(int i=0;i<m;i++){
        if(l>=r) break;
        if(st[l].first<=0){
            st[l+1].first-=st[l].first;
            t-=st[l+1].first;
            l++;
            continue;
        }
        if(st[r].first<=0){
            st[r-1].first-=st[r].first;
            t-=st[r-1].first;
            r--;
            continue;
        }
        if(st[l].second!=st[r].second){
            if(st[l].first>st[r].first){
                ans+=st[l].first;
                hc=st[l].first-st[r].first;
                t=hc;
                //cout<<endl<<hc<<endl;
                st[r-1].first-=hc;
                t-=st[r-1].first;
                r--;
                continue;
            }
            if(st[l].first<st[r].first){
                ans+=st[r].first;
                hc=st[r].first-st[l].first;
                t=hc;
                //cout<<endl<<hc<<endl;
                st[l+1].first-=hc;
                t-=st[l+1].first;
                l++;
                continue;
            }
            ans+=st[l].first;
            r--;
            l++;
        }
    }
    if(t>0) ans-=t;
    cout<<ans;
    return 0;
}
