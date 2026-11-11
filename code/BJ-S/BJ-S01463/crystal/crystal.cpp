#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n;
long long m;
long long sum,a[N];
int main(){
    //erfen?
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r+1)/2;
        //cout<<mid<<' '<<l<<' '<<r<<endl;
        deque<long long> q;
        long long sm=0;
        bool can=0;
        for(int i=1;i<=mid;i++){
            if(q.empty())q.push_front(a[i]);
            else{
                if(q.front()<a[i]){
                    sm+=(i-1)*(a[i]-q.front());
                    q.push_front(a[i]);
                }
                else{
                    sm+=q.front()-a[i];
                    while(q.back()<a[i])q.pop_back();
                    q.push_back(a[i]);
                }
            }
            //cout<<i<<' '<<q.front()<<' '<<sm<<endl;
        }
        if(sm<=m){
            l=mid;
            continue;
        }
        for(int i=mid+1;i<=n;i++){
            if(a[i-mid]==q.front()){
                q.pop_front();
                sm-=mid*(a[i-mid]-q.front());
            }
            else sm-=q.front()-a[i-mid];
            if(q.front()<a[i]){
                sm+=mid*(a[i]-q.front());
                q.push_front(a[i]);
            }
            else{
                sm+=q.front()-a[i];
                while(q.back()<a[i])q.pop_back();
                q.push_back(a[i]);
            }
           // cout<<i<<' '<<q.front()<<' '<<sm<<endl;
            if(sm<=m){
                can=1;
                break;
            }
        }
        if(can){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
