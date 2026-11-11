#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,char>> a;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;char y;
        cin>>x>>y;
        if(i!=1&&y==a[a.size()-1].second){
            a[a.size()-1].first+=x;
        }else{
            a.push_back({x,y});
        }
        sum+=x;
    }
    
    int mid=sum/2+1;
    int tmp1=0,tmpi1;
    for(int i=0;i<a.size();i++){
        if(tmp1+a[i].first>=mid){
            tmpi1=i;
            break;
        }
        tmp1+=a[i].first;
    }
    if(!(sum&1)){
        a[tmpi1].first++;
    }
    int st=tmp1+1;
    int ed=tmp1+a[tmpi1].first;
    int changetime=0;
    int l=tmpi1,r=tmpi1;
    if(mid-st>ed-mid)r++;
    else if(mid-st<ed-mid)l--;
    else l--,r++;

    // cout<<a[tmpi1].first<<endl;

    a[tmpi1].first-=(min(mid-st,ed-mid)*2)+1;

    // cout<<a[tmpi1].first<<endl;

    while(l>=0&&r<a.size()){

        // cout<<a[l].first<<" "<<a[r].first<<" "<<l<<" "<<r<<endl;
        
        if(a[l].first>a[r].first){
            if(a[l].second!=a[r].second) changetime+=a[r].first;
            a[l].first-=a[r].first;
            r++;
        }else if(a[l].first<a[r].first){
            if(a[l].second!=a[r].second) changetime+=a[l].first;
            a[r].first-=a[l].first;
            l--;
        }else{
            if(a[l].second!=a[r].second) changetime+=a[l].first;
            l--,r++;
        }

        // cout<<changetime<<"---\n";

    }
    cout<<changetime;
    return 0;
}