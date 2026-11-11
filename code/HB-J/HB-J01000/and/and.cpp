#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[2000005];
    vector<int>num;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    int l=num.size();
    for(int i=0;i<l;i++){
        if(m==0){
            cout<<num[i-1]<<endl;
        }
        m--;
    }
    return 0;
}
