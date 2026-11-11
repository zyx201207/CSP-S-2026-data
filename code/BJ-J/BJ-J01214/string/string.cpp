#include<bits/stdc++.h>
using namespace std;
long long l,n;
deque<pair<long long,char> > a;
long long k;
char t;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>t;
        a.push_back(make_pair(k,t));
    }
    while(a.size()>1){
        if(a.front().second!=a.back().second){
            sum+=min(a.front().first,a.back().first);
        }
        if(a.front().first>a.back().first){
            a.front().first-=a.back().first;
            a.pop_back();
        }else if(a.front().first<a.back().first){
            a.back().first-=a.front().first;
            a.pop_front();
        }else{
            a.pop_front();
            a.pop_back();
        }
    }
    cout<<sum;
    return 0;
}
