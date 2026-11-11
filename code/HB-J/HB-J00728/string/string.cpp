#include<bits/stdc++.h>
using namespace std;
struct word{
    long long a;
    char c;
};
word s[300005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    int l=1,r=n;
    while(l<=r){

        if(s[l].c!=s[r].c){
                ans+=min(s[l].a,s[r].a);
            if(s[l].a<s[r].a){
                s[r].a-=s[l].a;
                l++;
            }
            else if(s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
            }
            else if(s[l].a==s[r].a){
                l++;
                r--;
            }

        }
        else if(s[l].c==s[r].c){
             if(s[l].a<s[r].a){
                s[r].a-=s[l].a;
                l++;
            }
            else if(s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
            }
            else if(s[l].a==s[r].a){
                l++;
                r--;
            }
        }
    }

    cout<<ans;
    return 0;
}
