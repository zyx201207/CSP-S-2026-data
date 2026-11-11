#include<bits/stdc++.h>
using namespace std;
int n,m,s=-1,t;
vector<int> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>t;
        if(v.size()<m){
            v.push_back(t);
        }else{
            if(t>s){
                v.push_back(t);
                sort(v.rbegin(),v.rend());
                v.pop_back();
                s=v[m-1];
            }
        }
    }
    cout<<v[m-1];
    return 0;
}
