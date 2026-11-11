#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+10;
vector<pair<long long,char>> l,r;
long long a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long tj=0,temp=sum/2;
    if(sum%2==0){
        int i=1;
        while(tj+a[i]<=temp){
            tj+=a[i];
            pair<long long,char> t;
            t.first=a[i];
            t.second=c[i];
            l.push_back(t);
            i++;
        }
        if(tj<temp){
            pair<long long,char> t;
            t.first=temp-tj;
            t.second=c[i];
            l.push_back(t);
            a[i]-=(temp-tj);
            tj=temp;
        }
        while(i<=n){
            tj+=a[i];
            pair<long long,char> t;
            t.first=a[i];
            t.second=c[i];
            r.push_back(t);
            i++;
        }
    }else{
        int i=1;
        while(tj+a[i]<=temp){
            tj+=a[i];
            pair<long long,char> t;
            t.first=a[i];
            t.second=c[i];
            l.push_back(t);
            i++;
        }
        if(tj<temp){
            pair<long long,char> t;
            t.first=temp-tj;
            t.second=c[i];
            l.push_back(t);
            a[i]-=(temp-tj+1);
            if(a[i]<=0) i++;
            tj=temp+1;
        }
        while(i<=n){
            tj+=a[i];
            pair<long long,char> t;
            t.first=a[i];
            t.second=c[i];
            r.push_back(t);
            i++;
        }
    }
    long long ans=0;
    int i=0,j=r.size()-1;
    while(i<l.size()){
        if(l[i].first==r[j].first){
            if(l[i].second!=r[j].second){
                ans+=l[i].first;
            }
            i++,j--;
        }else if(l[i].first>r[j].first){
            if(l[i].second!=r[j].second){
                ans+=r[j].first;
            }
            l[i].first-=r[j].first;
            j--;
        }else if(l[i].first<r[j].first){
            if(l[i].second!=r[j].second){
                ans+=l[i].first;
            }
            r[j].first-=l[i].first;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
