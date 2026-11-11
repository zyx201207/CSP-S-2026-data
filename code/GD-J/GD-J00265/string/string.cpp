#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
pair<pair<int,int>,char> a[200005];
vector<pair<int,char> > l,r;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first.first>>a[i].second;
        int t=a[i].first.first;
        a[i].first.first=sum+1;
        sum+=t;
        a[i].first.second=sum;
    }
    //cerr<<sum<<endl;
    int ts=sum;
    sum=(sum+1)/2;
    l.push_back({0,'0'});
    if(ts&1){
        bool flg=0;
        for(int i=1;i<=n;i++){
            if(a[i].first.first<=sum  && sum<=a[i].first.second){
                if(a[i].first.first<sum){
                    l.push_back({sum-a[i].first.first,a[i].second});
                }
                if(sum<a[i].first.second){
                    r.push_back({a[i].first.second-sum,a[i].second});
                }
                flg=1;
            }else{
                if(!flg){
                    l.push_back({a[i].first.second-a[i].first.first+1,a[i].second});
                }else{
                    r.push_back({a[i].first.second-a[i].first.first+1,a[i].second});
                }
            }
        }
    }else{
        bool flg=0;
        for(int i=1;i<=n;i++){
            if(a[i].first.first<=sum  && sum<=a[i].first.second){
                l.push_back({sum-a[i].first.first+1,a[i].second});
                if(sum<a[i].first.second){
                    r.push_back({a[i].first.second-sum,a[i].second});
                }
                flg=1;
            }else{
                if(!flg){
                    l.push_back({a[i].first.second-a[i].first.first+1,a[i].second});
                }else{
                    r.push_back({a[i].first.second-a[i].first.first+1,a[i].second});
                }
            }
        }
    }
    r.push_back({0,'0'});
    reverse(r.begin(),r.end());
    //cerr<<sum<<endl;
    sum=0;
    for(auto i : l){
        // //cerr<<i.first<<" "<<i.second<<endl;
        sum+=i.first;
    }
    //cerr<<sum<<endl;
    //cerr<<endl;
    sum=0;
    for(auto i : r){
        // //cerr<<i.first<<" "<<i.second<<endl;
        sum+=i.first;
    }
    //cerr<<sum<<endl;
    //cerr<<endl;
    int L=1,suml=0;
    int R=0,sumr=0;
    int n=l.size()-1;
    int m=r.size()-1;
    int ans=0;
    // cout<<endl;
    //cerr<<n<<" "<<m<<endl;
    for(;L<=n;L++){
        //cerr<<L<<" "<<l[L].second<<":\n";
        suml=l[L].first;
        sumr=0;
        while(R<m && sumr+r[R+1].first<=suml){
            sumr+=r[R+1].first;
            if(r[R+1].second!=l[L].second){
                ans+=r[R+1].first;
            }
            R++;
            //cerr<<R<<" "<<r[R].first<<" "<<r[R].second<<endl;
        }
        if(R==m){
            //cerr<<suml<<" "<<sumr<<endl;
            break;
        }
        //cerr<<suml<<" "<<sumr<<endl;
        if(suml>sumr){
            //cerr<<"cut "<<R+1<<" "<<r[R+1].first<<" ";
            r[R+1].first-=suml-sumr;
            if(r[R+1].second!=l[L].second){
                ans+=suml-sumr;
            }
            //cerr<<r[R+1].first<<endl;
        }
        //cerr<<endl;
    }
    cout<<ans<<endl;
    return 0;
}