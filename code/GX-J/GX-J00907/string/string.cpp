#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    char b[1000000];
    int ans=0,sum=0;
    if(s.size()%2==1){
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[s.size()-i-1]){
                s[i]=s[s.size()-i-1];
                ans++;
            }
        }
        for(int i=s.size()/2+1;i>=s.size()-1;i--){
            if(s[i]!=s[s.size()-i-1]){
                s[s.size()-i-1]=s[i];
                sum++;
            }
        }
        cout<<min(sum,ans);
    }
    else{
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[s.size()-i-1]){
                s[i]=s[s.size()-i-1];
                ans++;
            }
        }
        for(int i=s.size()/2;i>=s.size()-1;i--){
            if(s[i]!=s[s.size()-i-1]){
                s[s.size()-i-1]=s[i];
                sum++;
            }
        }
        cout<<min(sum,ans);
    }
}

