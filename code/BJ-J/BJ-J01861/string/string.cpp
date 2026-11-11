#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,char> a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l=1,r=n;
    long long cnt=0;
    while(l<=r){
        if(a[l].second==a[r].second){
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                r--;
            }
            else if(a[l].first==a[r].first){
                l++;
                r--;
            }
            else{
                a[r].first-=a[l].first;
                l++;
            }
        }
        else{
            cnt+=min(a[l].first,a[r].first);
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                r--;
            }
            else if(a[l].first==a[r].first){
                l++;
                r--;
            }
            else{
                a[r].first-=a[l].first;
                l++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
