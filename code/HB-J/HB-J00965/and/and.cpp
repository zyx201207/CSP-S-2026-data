#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s[100000];
    s[0]=a[0];
    for(int i=0;i<n;i++){
        for(int j=i;j>=m;j--){
            s[j]=s[i-1];
            s[j]=max(a[j],s[j-a[i]]&a[i]);
        }
    }
    cout<<s[n-1];
    return 0;
}
