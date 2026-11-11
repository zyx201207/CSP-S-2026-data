#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t=0;
    string s;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        std::cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
        t+=a;
    }
    int su=0;
    for(int i=0,j=t-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            su++;
        }
    }
    std::cout<<su;
    fclose(stdin);
    fclose(stdout);
    return 0;
}