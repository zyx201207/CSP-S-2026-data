#include<bits/stdC++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a;
    int s[100000001];
    cin>>n>>a;
    for(int i;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    cout<<s[a];
    return 0;
}
