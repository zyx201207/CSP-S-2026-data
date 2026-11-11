#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
long long n,m,maxand=-1;
void d(int x,int s){
    if(s==0||x>=a.size()) return;
    for(int i=x;i<a.size();i++){
        b.push_back(a[i]);
        if(b.size()==m){
            long long an=b[0];
            for(int j=1;j<m;j++){
                an=an&b[j];
            }
            maxand=max(maxand,an);
        }
        d(i+1,s-1);
        b.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    d(0,m);
    cout<<maxand;
    return 0;
}
