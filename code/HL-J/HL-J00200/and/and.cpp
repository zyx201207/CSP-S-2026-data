#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>s;
int n,a[N],m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1){
                continue;
            }
            s.push_back(a[i]&&a[j]);
        }
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }
    return 0;
}
