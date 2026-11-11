#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
vector<int> v;
set<int> st;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    st.insert(a[i]);
    }
    for(auto t:st){
        v.push_back(t);
    }
    cout<<v[(v.size()+1)/2];
    return 0;
}
