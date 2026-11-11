#include<bits/stdc++.h>
using namespace std;
long long a[500005];

bool ispossible(int mid,long long m){
    for(int i=1; i<mid; i++){
        m -= (a[mid] - a[i]);
    }
    if(m >= 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    cin >> n;
    long long m;
    cin >> m;

    for(int i=1; i<=n ;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    int l=1;
    int r=n;
    while(l<r){
        int mid = (l + r + 1) / 2;
        if(ispossible(mid,m)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
