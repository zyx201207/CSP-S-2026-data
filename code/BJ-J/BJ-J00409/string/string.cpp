#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<char,ll>>b;
ll sum,mid;
void sol(){
    auto a=b;
    ll i=0,j=a.size()-1,ans=0;
    while(i<j){
        char ci=a[i].first,cj=a[j].first;
        ll cnti=a[i].second,cntj=a[j].second;
        if(cnti==0){
            ++i;
            continue;
        }
        if(cntj==0){
            --j;
            continue;
        }
        if(ci==cj){
            if(cnti>cntj){
                a[j-1].second-=(cnti-cntj);
                a[j].second+=(cnti-cntj);
                ans+=(cnti-cntj);
                //cout<<1;
            }
            if(cntj>cnti){
                a[i+1].second-=(cntj-cnti);
                a[i].second+=(cntj-cnti);
                ans+=(cntj-cnti);
                //cout<<2;
            }
        }else{
            if(cnti>=cntj){
                if(a[j-1].first==ci){
                    ans+=a[i].second;
                }
                else{
                    a[j-1].second-=(cnti-cntj);
                    a[j].second+=(cnti-cntj);
                    a[j].first=ci;
                    ans+=a[j].second;
                }
                //cout<<3;
            }
            if(cntj>cnti){
                if(a[i+1].first==cj){
                    ans+=a[j].second;
                }
                else{
                    a[i+1].second-=(cntj-cnti);
                    a[i].second+=(cntj-cnti);
                    a[i].first=ci;
                    ans+=a[i].second;
                }
                //cout<<4;
            }
        }
        --j;
        ++i;
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    vector<pair<char,ll>>a1;
    for(ll i=1;i<=n;++i){
        ll x;
        char y;
        cin>>x>>y;
        if(a1.size()&&y==a1[a1.size()-1].first){
            a1[a1.size()-1].second+=x;
        }else{
            a1.push_back({y,x});
        }
    }
    if(a1.size()==1){
        cout<<0;
        return 0;
    }
    for(auto [x,y]:a1){
        sum+=y;
    }
    bool flag=0;
    if(sum%2==1){
        mid=sum/2+1;
    }else{
        flag=1;
        mid=sum/2;
    }
    sum=0;
    //cout<<flag<<"\n";
    for(auto it=a1.begin();it!=a1.end();++it){
        char c=it->first;
        ll cnt=it->second;
        //cout<<sum<<" "<<sum+cnt<<"\n";
        if(sum<mid&&sum+cnt>=mid){
            if(!flag){
                b.push_back({c,mid-sum-1});
                b.push_back({c,1});
                b.push_back({c,sum+cnt-mid});
            }else{
                b.push_back({c,mid-sum});
                b.push_back({c,sum+cnt-mid});
            }
        }
        else{
            b.push_back({c,cnt});
        }
        sum+=cnt;
    }
    //for(auto [x,y]:b)
    //{
    //    cout<<x<<" "<<y<<"\n";
    //}
    sol();
    return 0;
}
