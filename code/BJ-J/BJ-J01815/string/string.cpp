#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[100001];
    string m[100001];
    int k = 0;
    long long cnt = 0;
    string s;
    for(int i = 1;i <= n; i++){
        cin>>a[i];
        cin>>s;
        cnt += a[i];
        for(int j = cnt - a[i]; j <= cnt; j++){
            m[j] = s;
        }
    }
    int mid = (cnt + 1) / 2;
    for(int i = 1; i < mid; i++){
        int l = 0, r = n;
        if(m[l] != m[r]){
            l++;
            r++;
            k++;
        }
    }
    cout<<k;
    return 0;
}
