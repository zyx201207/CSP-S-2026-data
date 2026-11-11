#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,sum=0;
    vector<char>s;
    vector<char>z;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s.push_back(c);
        }
    }
    for(int i=0;i<s.size();i++){
        if(n==1){
            cout<<sum;
            break;
        }
        else{
            for(int j=s.size();j>0;j--){
                z.push_back(s[j]);
            }
        }
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<z.size();j++){
            if(s[i]==z[j]){
                sum=0;
            }
            else{
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
