#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,a[N];
priority_queue<pair<int,int> > q;
int ans; 
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    pair<int,int> cur;
    int d;
    for(int i=1,dm;i<=n-1;i++){
        dm=0;vector<pair<int,int> > u;
        while(!q.empty()){
            cur=q.top();
            d=a[i]-a[i-1];
            if(d==0){
                q.pop();ans--;
                u.push_back(make_pair(cur.first,i));
            }
            else{
                dm-=d;
                q.pop();ans--;
                cur.first+=d;
                cur.second=i;
                u.push_back(make_pair(cur.first,i));
            }   
        }
        for(pair<int,int> v:u){
            q.push(v);ans++;
        }
        while(dm+m<0){
            cur=q.top();
            q.pop();ans--;
            dm+=cur.first;
        }
        m+=dm;
        if(q.empty()){
            if(a[i+1]-a[i]<=m){
                q.push(make_pair(a[i+1]-a[i],i));
                m-=(a[i+1]-a[i]);ans++;
            }
        }
        else{
            cur=q.top();
            if(m-(a[i+1]-a[i])>=0){
                q.push(make_pair(a[i+1]-a[i],i));
                m-=(a[i+1]-a[i]);ans++;
            }
            else if(a[i+1]-a[i]<cur.first){
                q.pop();
                q.push(make_pair(a[i+1]-a[i],i));
                m+=cur.first;
                m-=(a[i+1]-a[i]);
            } 
        }
    }
    cout<<ans;
    return 0;
}