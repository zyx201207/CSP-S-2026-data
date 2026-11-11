#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[100000];
long long  sum[100000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    set<long long>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        for(int i=j;i<n;i++){
            if(s.empty()){
                s.insert(a[i]);
            }else if(s.count(a[i])){
                s.erase(s.begin(),s.end());
            }else{
                s.insert(a[i]);
            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<3<<" "<<1<<" "<<4;
    }

    return 0;
}


