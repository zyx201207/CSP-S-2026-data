#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long s[10005]={0},l=0;
    char d[10005],fd[10005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>d[i];
        fd[n-i-1]=d[i];
    }
    int f=(n+1)/2;
    for(int i=0;i<f;i++){
        if(d[i]!=fd[i]){
            if(s[i]==s[n-i-1])
                l+=s[n-i-1];
            else l+=s[i];

        }
        else if(i==f-1&&l==0){
           cout<<0;
           return 0;
           }
    }
        cout<<l;

    return 0;
}
