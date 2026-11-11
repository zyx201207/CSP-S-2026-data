#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int x;
        char f;
        cin>>x>>f;


        for(int j=1;j<=x;j++){
           s+=f;
        }



    }
    //cout<<s<<" ";
    int len=s.length();
    //cout<<len;
    long long cnt =0;
    for(long long i=0;i<=(len/2);i++){
        if(s[i]!=s[len-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
