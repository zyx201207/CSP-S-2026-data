#include<bits/stdc++.h>
using namespace std;
int l,r,ans,n;
struct a{
    int c;
    char x;
}s[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].c>>s[i].x;
    }
    l=1;
    r=n;
    while(l<r){
        if(s[l].x==s[r].x){
            if(s[l].c>=s[r].c){
                s[l].c-=s[r].c;
                r--;
            }
            else{
                s[r].c-=s[l].c;
                l++;
            }
        }
        else{
            if(s[l].c>=s[r].c){
                s[l].c-=s[r].c;
                ans+=s[r].c;
                r--;

            }
            else{
                s[r].c-=s[l].c;
                ans+=s[l].c;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
