#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long a;
    char c;
}s[200005];

long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    int i=1,j=n+1;
    while(n--){
        if(i>=j){
            break;
        }
        if(s[i].c==s[j].c){
            if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }else if(s[i].a==s[j].a){
                i++;
                j--;
            }else if(s[i].a<s[j].a){
                s[j].a-=s[i].a;
                i++;
            }
        }else{
            if(s[i].a>s[j].a){
                ans+=s[j].a;
                s[i].a-=s[j].a;
                j--;
            }else if(s[i].a==s[j].a){
                ans+=s[j].a;
                i++;
                j--;
            }else if(s[i].a<s[j].a){
                ans+=s[i].a;
                s[j].a-=s[i].a;
                i++;
            }
        }

    }
    cout<<ans;
    return 0;
}
