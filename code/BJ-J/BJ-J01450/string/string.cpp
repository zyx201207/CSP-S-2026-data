#include<bits/stdc++.h>
using namespace std;
string str;
long long cnt;
struct node{
    long long L;
    char c;
}mp[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mp[i].L>>mp[i].c;
    }
    int l=1,r=n;
    while(l<r){
        long long m=min(mp[l].L,mp[r].L);
        if(mp[l].c!=mp[r].c){
            cnt+=m;
        }
        mp[l].L-=m;
        mp[r].L-=m;
        if(mp[l].L<=0)l++;
        if(mp[r].L<=0)r--;
    }
    cout<<cnt;
    return 0;
}
