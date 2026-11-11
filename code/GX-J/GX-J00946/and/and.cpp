#include<bits/stdc++.h>
using namespace std;
long long a[100000086];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    long long n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a,a+n,cmp);
    cout  << a[m-1];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    return 0;
}
