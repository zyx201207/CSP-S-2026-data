#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m;
int lg(int num){
    if(num==0) return -1;
    if(num==1) return 0;
    else return lg(num/2) +1 ;
}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> n >> m;
    int mx=0;
    int f=n;
    while(f--){
        int x;
        cin >> x;
        a.push_back(x);
        if(x>mx) mx=x;
    }
    int k=lg(mx);
    int ans=0;
    vector<int> remain;
    for(int i=0;i<n;i++){
        remain.push_back(i);
    }
    for(int j=k;j>0;j--){
        vector<int> v;
        for(int i=0;i<remain.size();i++){
            if(lg(a[remain[i]])==j){
                v.push_back(remain[i]);
                a[i]-=pow(2,j);
            }
        }
        if(v.size()>=m){
            int tmp=pow(2,j);
            ans+=tmp;
            remain=v;
        }
    }
    int count=0;
    for(int i=0;i<remain.size();i++){
        if(a[remain[i]]==1){
            count++;
        }
    }
    if(count>=m) ans++;
    cout << ans;
    return 0;
}
