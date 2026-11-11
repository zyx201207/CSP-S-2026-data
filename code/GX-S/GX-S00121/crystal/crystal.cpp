#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sec second
int ans,cnt;

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;
    vector<int> app;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<n;i++){
        int er;cin>>er;app.push_back(er);
    }
    sort(app.begin(),app.end());

    for(int i=0;i<n;i++){

    }


    //for(int v:app) cout << app[v] << ' ';
    for(int i=0;i<n-1;i++){
        int ks=abs(app[i+1]-app[i]);
        pq.push({ks,i});
    }


    while(!pq.empty()){
            ans=0;
        for(int i=pq.top().second,j=pq.top().second,w=pq.top().first;i>0,j<n-1;i--,j++){
            int chai=0,chaj=0;
        chai=chai+app[i]-app[i-1];chaj=chaj+app[j+1]-app[j];
        int cha=min(chai,chaj);
        m-=cha;ans++;
        if(m<=0) {
            ans--;break;
        }
        m=chai+chaj-min(chai,chaj);ans++;
        if(m<=0) {
            ans--;break;

    }
    }pq.pop();
        cnt=max(ans,cnt);

    }

    /*while(m>0){
        if(m<0) {
            break;
        }
    }*/

    cout << cnt;
    return 0;
}
