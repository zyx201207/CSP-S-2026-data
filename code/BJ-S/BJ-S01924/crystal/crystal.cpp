#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long ojj[100006];
long long osm=0;
long long notm=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ojj[i];
    }
    osm=ojj[0];
    sort(ojj,ojj+n);
    for(int y=n-1;y>=1;y--){
        notm=0;
        for(int z=y-1;z>=0;z--){
            notm+=ojj[y]-ojj[z];
        }
        if (notm <= m){
            ans+=y;#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long ojj[100006];
long long mid;
long long osm=0;
long long notm=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ojj[i];
    }
    osm=ojj[0];
    sort(ojj,ojj+n);
    for(int y=n-1;y>=1;y--){
        notm=0;
        for(int z=y-1;z>=0;z--){
            notm+=ojj[y]-ojj[z];
        }
        if (notm <= m){
            ans+=y;
            break;
        }
    }
    cout<<ans;
    return 0;
}
            break;
        }
    }
    cout<<ans;
    return 0;
}