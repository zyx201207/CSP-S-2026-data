#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    vector<string> a;
    cin>>n;
    int w = 0,cnt = 0;
    for(int i = 0;i<n;i++){
        int k;
        string q;
        cin>>k>>q;
        for(int j = 0;j<k;j++){
            a.push_back(q);
            w++;
        }
    }
    int l,r;
    for(int i = 0;i<w/2;i++){
        l = i;
        r = w-1-i;
        if(a[l] != a[r]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}