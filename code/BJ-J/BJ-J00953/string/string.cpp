#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l;
    vector<char> c;
    for(int i=0;i<n;i++){
        int temp_l;char temp_c;
        cin>>temp_l>>temp_c;
        for(int j=0;j<temp_l;j++){
            c.push_back(temp_c);
        }
    }
    int ans=0;
    for(int i=0;i<=c.size()/2;i++){
        if(c[i] - c[c.size()-1-i] != 0) ans++;
    }
    cout<<ans;
    return 0;
}