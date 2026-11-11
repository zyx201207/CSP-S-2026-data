#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<long long> arr  = {};
    for(int i = 0;i <n;i ++){
        cin >>arr[i];
    }
    sort(arr.begin(),arr.end())；
    for(int i = 0;i < n;i ++){
         cout << arr[arr.size() - m - 1];
    }
    return 0;
}

