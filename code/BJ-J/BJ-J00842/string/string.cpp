#include<bits/stdc++.h>
using namespace std;
const int N_e5=2e5+12;
pair<long long,string> pi[N_e5];
int main(){//24474
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char s;
        cin>>x>>s;
        //cout<<x<<" "<<s<<endl;
        pi[i].first=x;
        pi[i].second=s;
    }
    long long l=1,r=n;
    long long ans=0;
    while(l<=r){
        if(pi[l].second==pi[r].second) {
            if(pi[l].first==pi[r].first) l++,r--;
            else if(pi[l].first>pi[r].first){
                pi[l].first-=pi[r].first;
                r--;
            }else{//pi[l].first<p[r].first
                pi[r].first-=pi[l].first;
                l++;
            }
        }else{//pi[l].second!=pi[r].second
            if(pi[l].first==pi[r].first) ans+=pi[l].first,l++,r--;
            else if(pi[l].first>pi[r].first){
                pi[l].first-=pi[r].first;
                ans+=pi[r].first;
                r--;
            }else{//pi[l].first<p[r].first
                pi[r].first-=pi[l].first;
                ans+=pi[l].first;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
