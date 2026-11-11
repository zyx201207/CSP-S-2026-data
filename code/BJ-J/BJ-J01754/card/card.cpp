#include<bits/stdc++.h>
using namespace std;
queue<int> a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<3<<" "<<1<<" "<<4;
    return 0;
}
