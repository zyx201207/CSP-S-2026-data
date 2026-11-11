#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;
int n;
// string num,ans;
long long num,ans;
char c;
// deque<pair<string,char>> s;
deque<pair<long long,char>> s;
/*
void ssub(string &a,string &b){

    int n=max(a.size(),b.size());
    string c;
    cout<<a<<"\n";
    c.resize(n,'0');
    for(int i=0;i<n;i++){
        cout<<a<<"\n";
        if(a[i]<b[i]){
            a[i]+=10;
            a[i+1]--;
        }
        c[i]+=a[i]-b[i];
    }
    while(c.back()=='0') c.pop_back();
    a=c;
    cout<<a<<"\n";
}
void sadd(string &a,string &b){
    int n=max(a.size(),b.size());
    string c;
    c.resize(n+1,'0');
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i]-'0';
        if(c[i]>'9'){
            c[i+1]++;
            c[i]-=10;
        }
    }
    while(c.back()=='0') c.pop_back();
    a=c;
}
*/
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num>>c;
        // reverse(num.begin(),num.end());
        s.push_back(make_pair(num,c));
    }
    while (!s.empty())
    {
        // pair<string,char> &l=s.front(),&r=s.back();
        pair<long long,char> &l=s.front(),&r=s.back();
        if(l.second==r.second){
            if(l.first>=r.first){
                // ssub(l.first,r.first);
                l.first-=r.first;
                s.pop_back();
            }
            else{
                // ssub(r.first,l.first);
                r.first-=l.first;
                s.pop_front();
            }
        }
        else{
            if(l.first>=r.first){
                // sadd(ans,r.first);
                // ssub(l.first,r.first);
                ans+=r.first;
                l.first-=r.first;
                s.pop_back();
            }
            else{
                // sadd(ans,l.first);
                // ssub(r.first,l.first);
                ans+=l.first;
                r.first-=l.first;
                s.pop_front();
            }
            
        }
    }
    // reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}