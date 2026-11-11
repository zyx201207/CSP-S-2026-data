#include<bits/stdc++.h>//rp++
using namespace std;
long long n[1000100],ans2[26],t=0;
char m[1000100],ans1[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    long long a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n[i]>>m[i];
    }int f=1;
    for(int i=0;i<a;i++){
        if(m[i]!=m[i+1])f=0;break;
    }
    if(f==1){cout<<0;return 0;}


    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(m[j]==ans1[i])
            ans2[i]++;
        }
    }
    for(int i=0;i<26;i++){
        if(ans2[i]!=0)t++;
    }
    cout<<t*n[0];
}
