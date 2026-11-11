#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    long long n,m;
    cin >> n >> m;
    long long arr[1000010];
    for (long long i=0;i<n;i++){
        long long a;
        cin >> a;
        arr[i]=a;
    }
    sort(arr,arr+n,cmp);
    long long max_v=0;
    int j=0;
    max_v = arr[j] ;
    for (int f=0;f<m;f++){
        max_v = max_v &arr[j+f];
    }


    cout << max_v;
    return 0;
}

