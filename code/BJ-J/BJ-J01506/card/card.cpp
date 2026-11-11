#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m,j[1e6]={0};
int xx(vector<int> a,vector<int> z){
    while(a){
        if(sizeof(z)<2){
            break;
        }
        while(int i=0;i<sizeof(z);i++){
            if(z[i]==a.top()){
                while(k=0;k<sizeof(z)-i;k++){
                    z.pop();
                }
            }
        }
        z.push_back(a.top());
        a.pop();
    }
    for(int i=0;i<sizeof(z);i++){
        j[z[i]]++;
    }
}
int main(){
    vector<int> a,z;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdiout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        vector<int> s;
        for(int k=i;k<n;k++){
            s.push_back(a[k]);
        }
        xx(s,z);
    }
    for(int i=0;i<m;i++){
        cout<<j[m]<<" ";
    }
    return 0;
}