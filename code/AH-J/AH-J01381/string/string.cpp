#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    char c;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    int l=1,r=n;
    long long cnt=0;
    while(1){
        if(l>=r){
            break;
        }
        int mins=min(s[l].a,s[r].a);
        if(s[l].c==s[r].c){
            s[l].a-=mins;
            s[r].a-=mins;
            if(s[l].a==0){
                l++;
            }
            if(s[r].a==0){
                r--;
            }
        }else{
            cnt+=mins;
            s[l].a-=mins;
            s[r].a-=mins;
            if(s[l].a==0){
                l++;
            }
            if(s[r].a==0){
                r--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
