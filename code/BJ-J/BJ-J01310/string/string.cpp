#include<bits/stdc++.h>
using namespace std;
struct nd{
    int a;
    char c;
}s[200001];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].c;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1,j=n;i<j;){
        if(s[i].a==s[j].a){
            if(s[i].c==s[j].c){
                i++,j--;
                continue;
            }
            else ans+=s[j].a;
            i++,j--;
        }
        else if(s[i].a>s[j].a){
            s[i].a-=s[j].a;
            if(s[i].c==s[j].c){
                j--;
                continue;
            }
            ans+=s[j].a;
            j--;
        }
        else{
            s[j].a-=s[i].a;
            if(s[i].c==s[j].c){
                i++;
                continue;
            }
            ans+=s[i].a;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
