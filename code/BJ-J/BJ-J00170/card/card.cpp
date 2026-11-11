#include <bits/stdc++.h>
#include <vector> 
#include <cmath>
using namespace std;
int main(){
    int m,n;
    cin<<n<<m;
    vector<pair<int,int> in1[n];
    for(int i=0;i<n;i++){
        cin>>in1[i].first;
        inl.second=i;
    }
    for(int i=1;i<=m;i++){
        if(m==in1[n-1].first){
            cout<<n;
        }
        int lisk;
        for(int j=0;j<=n;j++){
            if(m==in1[j].first){
                lisk=j;
            }
        }
        for(int j=lisk;j<=n;j++){
            if(in1[j].first<inl[lisk].first){
                cout<<n-lisk-j;
                break;
            }
        }
        cout<<n;
        
    }
return 0;
}