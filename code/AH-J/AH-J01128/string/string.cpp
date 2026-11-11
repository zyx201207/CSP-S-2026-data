#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
vector<pair<long long,char> >a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long x,len=0;
    char s;
    cin>>n>>x>>s;
    len+=x;
    a.push_back({x,s});
    for(long long i=1;i<n;++i){
        cin>>x>>s;
        len+=x;
        if(a.back().second==s){
            a.back().first+=x;
        }else{
            a.push_back({x,s});
        }
    }
    if(a.size()==1){
        cout<<'0';
        return 0;
    }
    vector<pair<pair<long long,long long>,char> >l,r;
    long long mid=len/2,b=1,i=0;
    while(b+a[i].first-1<=mid){
        l.push_back({{b,b+a[i].first-1},a[i].second});
        b+=a[i].first;
        ++i;
    }
    long long j=a.size()-1,c=1;
    while(c+a[j].first-1<=mid){
        r.push_back({{c,c+a[j].first-1},a[j].second});
        c+=a[j].first;
        --j;
    }
    if(l.empty()||l.back().first.second!=mid){
        l.push_back({{b,mid},a[i].second});
    }
    if(r.empty()||r.back().first.second!=mid){
        r.push_back({{c,mid},a[j].second});
    }


    for(auto i:l){
        cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<'\n';
    }
    cout<<'\n';
    for(auto i:r){
        cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<'\n';
    }

    if(l==r){
        cout<<'0';
        return 0;
    }
    i=0,j=0;
    for(long long i=0,j=0;i<l.size();++i){
        while(j<r.size()&&r[j].first.second<=l[i].first.second){
            long long l1=l[i].first.first;
            long long r1=l[i].first.second;
            long long l2=r[j].first.first;
            long long r2=r[j].first.second;
            if(r[j].second!=l[i].second){
                if(l1>=l2&&r1>=r2){
                    ans+=r2-l1+1;
                }else if(l1<=l2&&r1<=r2){
                    ans+=r1-l2+1;
                }else if(l1<=l2&&r1>=r2){
                    ans+=r2-l2+1;
                }else if(l1>=l2&&r1<=r2){
                    ans+=r1-l1+1;
                }
            }
            ++j;
        }
    }
    cout<<ans;
    return 0;
}
