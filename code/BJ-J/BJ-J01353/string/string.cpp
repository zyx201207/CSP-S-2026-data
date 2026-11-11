#include<string>
#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    cin>>n;
    string str;
    char c;
    for(int i=0,x;i<n;i++){
        cin>>x>>c;
        str.append(x,c);
    }
    size_t mid=(str.length()+1)/2,ans=static_cast<size_t>(0);
    for(int i=0;i<mid;i++)
        if(str[i]!=str[str.length()-i-1])ans++;
    cout<<ans;
    return 0;
}