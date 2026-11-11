#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long len=1,sum=0;
    char b;
    cin>>n;
    for(int i=1;i<=n;i++){
        char b;
        int a;
        cin>>a>>b;
        while(a--){
            len++;
            s[len]=b;
        }
    }

    for(long long i=1;i<=len/2;i++){
        if(s[i]!=s[len-i]) sum++;
    }
    cout<<sum;
    return 0;
}//NOI don't let me TLE!!!!!!!!!!!!!
