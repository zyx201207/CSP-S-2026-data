#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s,s1;
    cin>>n>>m;
    char a[n];
    int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s1=s;
    for(int q=1;q<=n;q++){
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[j]==s[i]){
                for(int k=i+1;k<n;k++){
                    s=s-s[k];
                }
            }
        }
    }
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s.size();j++){
            if(s[j]==s1[i]){
                b[j]++;
            }
        }
    }
    }
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
