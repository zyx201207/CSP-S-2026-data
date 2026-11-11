#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        string b;
        cin>>m>>b;
        for(int j=0;j<m;j++){
            s+=b;
        }
    }
    int p=s.size()-1,sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[p]){
            s[p]=s[i];
            sum+=1;
        }
        p-=1;
    }
    cout<<sum;
    return 0;
}
