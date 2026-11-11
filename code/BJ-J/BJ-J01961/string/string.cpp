
#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num;char c;
}s[200005];
int n;long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].num>>s[i].c;
    }
    int l=1,r=n;
    while(l<=r){
        if(s[l].c!=s[r].c){
            if(s[l].num>s[r].num) {
                ans+=s[r].num;
                s[l].num-=s[r].num;
                r--;
            }
            else if(s[l].num<s[r].num){
                ans+=s[l].num;
                s[r].num-=s[l].num;
                l++;
            }
            else {ans+=s[l].num;l++;r--;}
        }
        else{
            if(s[l].num>s[r].num) {
                s[l].num-=s[r].num;
                r--;
            }
            else if(s[l].num<s[r].num){
                s[r].num-=s[l].num;
                l++;
            }
            else {l++;r--;}
        }
    }
    cout<<ans;
    return 0;
}
