//GZ-J00267 贵阳市观山湖区第一高级中学 曹映森
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    vector<int> a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    long long sum=a[0];
    for(int i=1;i<m;i++){
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}
