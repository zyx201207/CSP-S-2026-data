#include <bits/stdc++.h>
using namespace std;
int main(){
    //rp+=inf!!!rp+=LLONG_MAX!!!rp+++++++++++++++++++++!!!!!IAKIOI!!!
    //思路：先恢复原本的字符串，然后遍历一半查看与另一半不同的数量
    //反例：暂无
    //我靠这个数据有一点大阿（惊）理论最大2e5x1e9???
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a,cnt=0;
    char b;
    string o;
    cin>>n;
    set<int> t;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        t.insert(b);
        o+=string(a,b);
    }
    if(t.size()==1){
        cout<<0;
        return 0;
    }
    //1 2 3 4 5
    //0 1 2 3 4
    //04 13 22
    for(int i=0;i<ceil(double(o.size())/2.0);i++){
        if(o[i]!=o[o.size()-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
