#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k=-1;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s[++k]=c;
        }
    }
    long long cnt=0,b=1;
    if(k%2==0){
        b=0;
    }
    for(int i=k-1;i>=(k-b)/2;i--){
        if(s[i]!=s[k-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}