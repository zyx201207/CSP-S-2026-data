#include<bits/stdc++.h>
using namespace std;
struct node{
    long a;
    char c;
}s[200005];
int n;
unsigned long long ans;
bool b=0;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
    for(int i=1;;){
        for(int j=n;;){
            if(s[i].c==s[j].c){
                long v=min(s[i].a,s[j].a);
                s[i].a-=v;
                s[j].a-=v;
                if(s[i].a==0) i++;
                if(s[j].a==0) j--;
            }
            else {
                long o=min(s[i].a,s[j].a);
                ans+=o;
                s[i].a-=o;
                s[j].a-=o;
                if(s[i].a==0) i++;
                if(s[j].a==0) j--;
            }
            if(i>=j) {
                b=1;
                break;
            }
        }
        if(b) break;
    }
    cout<<ans;
    return 0;
}
