
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int b;
        char c;
        cin>>b>>c;
        for(int j=0;j<b;j++){
            s+=c;
        }
    }


    string x;
    int sum=0;

    for(int i=s.length()-1;i>=0;i--){
        x+=s[i];
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!=x[i])
            sum++;
    }
    cout<<sum/2;

    return 0;
}
