#include<bits/stdc++.h>
using namespace std;

int n;
struct st{
    long long a;
    char c;
}s[200005];

string str;//work as real string

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        len+=s[i].a;
    }

    bool fc=true;//all same char?
    for(int i=1;i<=n;i++){
        if(i!=n&&s[i].c!=s[i+1].c){
            fc=false;
            break;
        }
    }
    if(fc){
        cout<<0;
        return 0;
    }//no prob

    long long ans=0;
    bool fa=true;//all same num?
    for(int i=1;i<=n;i++){
        if(i!=n&&s[i].a!=s[i+1].a){
            fa=false;
            break;
        }
    }
    if(fa){
        for(int i=1;i<=n;i++)
            str+=s[i].c;
        for(int i=0;i<str.size()/2;i++){//run half
            if(str[i]!=str[str.size()+1-i])
                ans+=s[1].a;
        }
        cout<<ans;
    }//seems ok
    else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=s[i].a;j++)
                str+=s[i].c;
        for(int i=0;i<len/2;i++)
            if(str[i]!=str[len+1-i]) ans++;
        cout<<ans;
    }

    return 0;
}
