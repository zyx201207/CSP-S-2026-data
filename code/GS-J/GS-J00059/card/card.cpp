#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,t,s[300010][300010];
    cin >> n >> m;
    vector<long long> a;
    for(int i = 0;i<n){
        cin >> t;
        a.push_back(t);
    }
    for(int i = 0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
            }
        }
    }
    for(int i=0;i<m;i++){
        cout << 0;
        if(i!=m-1){
            cout << ' ';
        }
    }
    return 0;
}
