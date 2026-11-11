#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    vector<int> a;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        a.push_back(v);
    }
    sort(a.begin(),a.end());
    if(m==1){
        cout << a[n-1];
    }
    else{
        cout << a[n/2];
    }
    return 0;
}
