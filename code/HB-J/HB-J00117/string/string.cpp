#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[INT_MAX];
    char rst[INT_MAX];
    memset(str,0,sizeof(str));
    memset(rst,0,sizeof(rst));
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long now=0;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            str[now]=c;
            rst[now]=c;
            now++;
        }
    }
    int cnt=0;
    reverse(rst,rst+now);
    for(int i=0;i<=now;i++){
        if(str[i]==rst[i]){
            cnt++;
        }
    }
    cout<<(now+1-cnt)/2;
    return 0;
}